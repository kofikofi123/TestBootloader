BITS 32
section .text
	global flush_gdt
	global get_registers
	

get_registers:
    push esp
    push ebp
    mov ebx, esp
    mov ebp, esp 
    
    lea esp, [ebp + 48]
    pushfd 
    pushad 
    push ds 
    push es 
    push gs 
    push fs 
    push ss 
    push cs 
    
    
    
    
.done:
    mov esp, ebx 
    pop ebp 
    pop esp 
    ret
	
flush_gdt:
	push ebx
	extern gdtp
	
	mov ebx, esp
	lgdt [gdtp]
	
	jmp 0x08:.flush 
.flush:
	mov ax, 0x10 
	mov ds, ax 
	mov es, ax 
	mov gs, ax
	mov fs, ax 
	mov ss, ax
	mov esp, ebx
	
	jmp 0x08:.done
.done:
	pop ebx
	ret