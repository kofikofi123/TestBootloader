section .text
	global flush_idt
	global flush_gdt
	
	
	
flush_idt:
	extern idtp
	
	lidt [idtp]
	
	ret

	
flush_gdt:
	extern gdtp
	
	lgdt [gdtp]
	
	jmp 0x80:.flush 
.flush:
	mov ax, 0x10 
	mov ds, ax 
	mov es, ax 
	mov gs, ax
	mov fs, ax 
	mov ss, ax 
	mov esp, 0x90000
	
	ret
	