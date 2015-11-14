section .text
	global irq0
	global irq1
	global irq2
	global irq3
	global irq4
	global irq5
	global irq6
	global irq7
	global irq8
	global irq9
	global irq10
	global irq11
	global irq12
	global irq13
	global irq14
	global irq15
	
irq0:
	push word 0
	push word 32
	
	jmp irq_main
irq1:
	push word 0
	push word 33
	
	jmp irq_main
irq2:
	push word 0
	push word 34
	
	jmp irq_main
irq3:
	push word 0
	push word 35
	
	jmp irq_main
irq4:
	push word 0
	push word 36
	
	jmp irq_main
irq5:
	push word 0
	push word 37
	
	jmp irq_main
irq6:
	push word 0
	push word 38
	
	jmp irq_main
irq7:
	push word 0
	push word 39
	
	jmp irq_main
irq8:
	push word 0
	push word 40
	
	jmp irq_main
irq9:
	push word 0
	push word 41
	
	jmp irq_main
irq10:
	push word 0
	push word 42
	
	jmp irq_main
irq11:
	push word 0
	push word 43
	
	jmp irq_main
irq12:
	push word 0
	push word 44
	
	jmp irq_main
irq13:
	push word 0
	push word 45
	
	jmp irq_main
irq14:
	push word 0
	push word 46
	
	jmp irq_main
irq15:
	push word 0
	push word 47
	
	jmp irq_main
	
	
irq_main:
	pushad
	
	push ds
	push es 
	push gs 
	push fs 
	push ss 
	
	mov ax, 0x10
	mov ds, ax 
	mov es, ax 
	mov fs, ax 
	mov gs, ax 
	mov ss, ax 
	
	extern irq_handler
	call irq_handler
	
	pop ss 
	pop fs 
	pop gs 
	pop es 
	pop ds 
	
	popad
	add esp, 4
	iret