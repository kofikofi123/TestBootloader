section .text
  global isr0
  global isr1
  global isr2
  global isr3
  global isr4
  global isr5
  global isr6
  global isr7
  global isr8
  global isr9
  global isr10
  global isr11
  global isr12
  global isr13
  global isr14
  global isr15
  global isr16
  global isr17
  global isr18
  global isr19
  global isr20
  global isr21
  global isr22
  global isr23
  global isr24
  global isr25
  global isr26
  global isr27
  global isr28
  global isr29
  global isr30
  global isr31
  

;Not done

isr0:
  push word 0
  push word 0
  jmp isr_main
  
isr1:
  push word 0
  push word 1 
  jmp isr_main
isr2:
  push word 0
  push word 2
  jmp isr_main
isr3:
  push word 0
  push word 3
  jmp isr_main
isr4:
  push word 0
  push word 4
  jmp isr_main
isr5:
  push word 0
  push word 5 
  jmp isr_main
isr6:
  push word 0
  push word 6 
  jmp isr_main
isr7:
  push word 0
  push word 7 
  jmp isr_main
isr8:
  push word 8
  jmp isr_main
isr9:
  push word 0
  push word 9 
  jmp isr_main
isr10:
  push word 10 
  jmp isr_main
isr11:
  push word 11
  jmp isr_main
isr12:
  push word 12
  jmp isr_main
isr13:
  push word 13
  jmp isr_main
isr14:
  push word 14
  jmp isr_main
isr15:
  push word 0
  push word 15
  jmp isr_main
isr16:
  push word 0
  push word 16
  jmp isr_main
isr17:
  push word 17
  jmp isr_main
isr18:
  push word 0
  push word 18
  jmp isr_main
isr19:
  push word 0
  push word 19
  jmp isr_main
isr20:
  push word 0
  push word 20
  jmp isr_main
isr21:
  push word 0
  push word 21
  jmp isr_main
isr22:
  push word 0
  push word 22
  jmp isr_main
isr23:
  push word 0
  push word 23
  jmp isr_main
isr24:
  push word 0
  push word 24
  jmp isr_main
isr25:
  push word 0
  push word 25
  jmp isr_main
isr26:
  push word 0
  push word 26
  jmp isr_main
isr27:
  push word 0
  push word 27
  jmp isr_main
isr28:
  push word 0
  push word 28
  jmp isr_main
isr29:
  push word 0
  push word 29 
  jmp isr_main
isr30:
  push word 30
  jmp isr_main
isr31:
  push word 0
  push word 31 
  jmp isr_main
  
isr_main:
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
	
	extern isr_handler
	call isr_handler
	
	pop ss 
	pop fs 
	pop gs 
	pop es 
	pop ds 
	
	popad
	add esp, 4
	iret
