;not done
BITS 16
ORG 0x7E00

jmp Main


;print_string:
;	cld
;	push ax
;._read:
;	lodsb
;	or al, al
;	jz ._done
;	mov ah, 0x0E
;	int 0x10
;	jmp short ._read
;._done:
;	pop ax
;	ret



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
	
os_information:
	db 0 ;flags
	
Main:	
	xor ax, ax
	mov ds, ax
	mov es, ax 
	mov gs, ax
	mov fs, ax 
	mov ax, 0x7C00
	mov ss, ax 
	mov sp, 0x7DFF
	
check_for_pci:
	lea si, [os_information]
	
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
replop:
	jmp replop
load_the_gdt:
	call load_gdt 

	
	
	cli
	mov eax, cr0 
	or eax, 1 
	mov cr0, eax 
	
	jmp 0x08:flush

BITS 32
	
flush:
	mov ax, 0x10 
	mov ds, ax 
	mov es, ax 
	mov gs, ax
	mov fs, ax 
	mov ss, ax 
	mov esp, 0x90000
	
	jmp 0x08:0x10000