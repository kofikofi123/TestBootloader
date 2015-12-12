BITS 32
section .text
	global flush_idt
	global flush_gdt
	
	
	
flush_idt:
	extern idtp
	
	lidt [idtp]
	
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