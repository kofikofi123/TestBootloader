;not done
BITS 16
ORG 0x7E00

jmp Main


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

detect_pci:
	pusha 
	mov ax, 0xb101
	xor edi, edi 
	int 0x1A
	
	cmp edx, 20494350h
	jne .error 
	push ax 
	mov al, 0b10000000 
	mov byte [boot_settings + 3], al 
	pop ax
	mov byte [boot_settings], al
	
.error:
	mov al, 0b00000000
	mov byte [boot_settings + 3], al 
	jmp .done
.done:
	popa 
	ret 
detect_memory:
    push ebx
    push ecx 
    push edx 
    push di
    lea di, [mdv]
	add di, 4
    xor ebx, ebx
	mov ecx, 0
.read:
	push ecx 
    mov eax, 0x0000E820 
    mov edx, 0x534D4150
    mov ecx, 24 
    int 0x15 
    jc short .error
    test ebx, ebx 
    jz short .finished
    
	pop ecx 
	inc ecx 
    add di, 24
    jmp .finished
.error:
    lea si, [could_not_detect_memory_error]
    call print_string
    mov eax, 1 
    ret 
.finished:
	pop ecx
	mov dword [mdv], ecx
    xor eax, eax 
    pop di 
    pop edx 
    pop ecx
    pop ebx 
    ret 
    
load_gdt:
	lgdt [gdt] 
	ret 

is_a20_enabled:
	push ax
	push cx 
	push bx 
	push ds 
	push gs
	
	mov ax, 0 
	mov ds, ax 
	not ax 
	mov es, ax 
	
	mov bx, [ds:0x7DFE]
	mov cx, [es:0x7E0E]
	
	
	cmp cx, bx 
	mov ax, 0 
	je .done
	
	mov ax, bx 
	
	mov byte [ds:0x7DFE], 0xA3 ; >:
	
	mov bx, [ds:0x7DFE]
	mov cx, [ds:0x7E0E]
	
	cmp cx, bx 
	mov ax, 0 
	je .done 
	mov ax, 1
.done:
	pop gs
	pop ds
	pop bx 
	pop cx 
	pop ax
	ret
	
gdt_start:
	;null
	dd 0 
	dd 0
	;code
	;limit = 0x0FFF
	;base = 0x00008000
	dw 0xFFFF 
	dw 0
	db 0 
	db 10011010b
	db 11001111b
	db 0
	
	dw 0xFFFF 
	dw 0
	db 0 
	db 10010010b
	db 11001111b
	db 0

gdt_end:

gdt: 
	dw gdt_end - gdt_start - 1 
	dd gdt_start
	
;os_information:
;	db 0 ;flags
	
Main:	
	xor ax, ax
	mov ds, ax
	mov es, ax 
	mov gs, ax
	mov fs, ax 
	mov ax, 0x7C00
	mov ss, ax 
	mov sp, 0x7DFF
	
	call detect_memory 
	call detect_pci
	cmp eax, 1 
	je short replop
;check_for_pci:
	;lea si, [os_information]
	
	;or [si], 1 ;for now
	
check_a20_loop:
	call is_a20_enabled
	cmp ax, 1 
	je load_the_gdt
	mov ax, 0x2401
	int 0x15
	call is_a20_enabled
	cmp ax, 1
	je load_the_gdt
	lea si, [error_loading_gdt_message]
	call print_string 
replop:
    cli 
    hlt
	jmp replop
load_the_gdt:
	call load_gdt 

	lea si, [mdv]
	
	cli
	mov eax, cr0 
	or eax, 1 
	mov cr0, eax 
	
	jmp 0x08:flush

error_loading_gdt_message db "Error: System doesn't support a20 ", 0
could_not_detect_memory_error db "Error: Couldn't get memory map", 0
test1 db "test1", 0
;mem_magic_number dw 0
boot_settings dd 0 
section .bss
mdv: resb 1540 ;maybe
BITS 32
section .text
flush:
	mov ax, 0x10 
	mov ds, ax 
	mov es, ax 
	mov gs, ax
	mov fs, ax 
	mov ss, ax 
	mov esp, 0x90000
	
	jmp 0x08:0x10000