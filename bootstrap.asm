BITS 16
ORG 0x7C00
jmp 0x0000:main

print_string:
	cld
	push ax
._read:
	lodsb
	or al, al
	jz ._done
	mov ah, 0x0E
	int 0x10
	jmp short ._read
._done:
	pop ax
	ret

	

reset_disk:
	mov ah, 0
	mov dl, [bdrive]
	int 0x13
	ret


;main
main:
	xor ax, ax
	mov ds, ax
	mov es, ax
	
	cli
	mov ax, 0x8C00
	mov ss, ax
	mov sp, 0x9C00
	sti
	
	
	mov [bdrive], dl
	pusha
	mov cx, 4
read_volume_descriptor:
	lea ax, [buffer]
	mov word [address], ax 
	mov ah, 0x42
	mov dl, [bdrive]
	lea si, [Disk_address_packet]
	
	int 0x13
	
	jnc read_volume_descriptor_success
	call reset_disk
	loop read_volume_descriptor
	jmp read_fail

read_volume_descriptor_success:
	popa
	lea di, [buffer + 1]
	lea si, [filesystem_identification]
	mov cx, 5
	rep cmpsb
	
	jne incorrect_fs
	lea bx, [buffer]
	jmp find_directory_table
	
find_directory_table:
	movzx ax, [bx] ;get the type of filesystem 
	cmp ax, 1 
	jne incorrect_fs
	lea bx, [buffer+156] ; go to start of directory
	mov ax, [bx + 2]
	mov dword [location], 0x00000000 ;clear first dword
	mov [location], ax 
	lea ax, [buffer]
	mov [address], ax
	mov word [address + 2], 0x0000
	pusha 
	mov cx, 4
read_directory_table:
	mov ah, 0x42 
	mov dl, [bdrive]
	lea si, [Disk_address_packet]
	
	int 0x13 
	mov dx, 34
	jnc directory_table_in_buffer
	loop read_directory_table
	jmp read_fail
	
directory_table_in_buffer:
	popa
	lea bx, [buffer]
	xor dx, dx
	jmp search_directory
search_directory:
	add bx, dx
	xor dx, dx 
	mov dx, [bx]
	cmp dx, 0 
	je hang
	
	mov cx, 10
	lea si, [kernel_name]
	lea di, [bx + 33]
	rep cmpsb
	
	je found_kernel
	jmp search_directory
found_kernel:
	mov word [address], 0
	mov word [address + 2], 0x1000
	mov ax, word [bx + 2]
	mov dword [location], 0
	mov  [location], ax 
	mov word [sectors_to_read], 3
	pusha
	mov cx, 3
load_kernel:
	lea si, [Disk_address_packet]
	mov dl, [bdrive]
	mov ah, 0x42 
	
	int 0x13 
	
	jnc kernel_loaded
	call reset_disk
	jmp load_kernel
	
	
kernel_loaded:
	
	;HOORAY, but we now have to load the stage2 boot
	popa
	lea bx, [buffer]
	xor dx, dx
find_stage2:
	add bx, dx
	xor dx, dx
	mov dx, [bx]
	cmp dx, 0
	je hang
	lea si, [stage2_name]
	lea di, [bx + 33]
	mov cx, 9 ;BOOT2.bin
	rep cmpsb
	
	je found_stage2
	jmp find_stage2
	
found_stage2:
	lea ax, [buffer]
	mov word [address], ax
	mov word [address + 2], 0x00000000
	mov ax, word [bx + 2]
	mov dword [location], 0
	mov [location], ax 
	
	mov word [sectors_to_read], 1
	
	pusha
	mov cx, 4
load_stage2:
	lea si, [Disk_address_packet]
	mov dl, [bdrive]
	mov ah, 0x42
	
	int 0x13
	
	jnc stage2_loaded
	call reset_disk
	loop load_stage2
	jmp read_fail
stage2_loaded:
	popa
	;clear registers >:
	xor ax, ax 
	xor bx, bx
	xor cx, cx 
	xor dx, dx 
	xor si, si 
	xor di, di
	jmp buffer
read_fail:
	popa 
	lea si, [read_failed]
	call print_string
	jmp hang
incorrect_fs:
	lea si, [incorrect_filesystem]
	call print_string
	jmp hang
	
hang:
	cli
	hlt
	jmp hang

Disk_address_packet:
		db 16
		db 0
		sectors_to_read:
		dw 1
		address:
		dw 0x7E00
		dw 0
		location:
		dd 16 
		dd 0


bdrive db 0
kernel_name db "KERNEL.BIN"
kernel_name_size equ $-kernel_name
stage2_name db "BOOT2.BIN"
stage2_name_size equ $-stage2_name
;messages
filesystem_identification db "CD001", 0
read_failed db "read failed", 0
incorrect_filesystem db "Incorrect filesystem", 0
;265537767
times 510-($-$$) db 0
db 0x55
db 0xAA
buffer:
	times 2048 db 0
