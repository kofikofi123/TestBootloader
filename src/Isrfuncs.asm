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
  cli
  push  0
  push  0
  jmp isr_main
  
isr1:
  cli
  push  0
  push  1 
  jmp isr_main
isr2:
  cli
  push  0
  push  2
  jmp isr_main
isr3:
  cli
  push  0
  push  3
  jmp isr_main
isr4:
  cli
  push  0
  push  4
  jmp isr_main
isr5:
  cli
  push  0
  push  5 
  jmp isr_main
isr6:
  cli
  push  0
  push  6 
  jmp isr_main
isr7:
  cli
  push  0
  push  7 
  jmp isr_main
isr8:
  cli
  push  8
  jmp isr_main
isr9:
  cli
  push  0
  push  9 
  jmp isr_main
isr10:
  cli
  push  10 
  jmp isr_main
isr11:
  cli
  push  11
  jmp isr_main
isr12:
  cli
  push  12
  jmp isr_main
isr13:
  cli
  push  13
  jmp isr_main
isr14:
  cli
  push  14
  jmp isr_main
isr15:
  cli
  push  0
  push  15
  jmp isr_main
isr16:
  cli
  push  0
  push  16
  jmp isr_main
isr17:
  cli
  push  17
  jmp isr_main
isr18:
  cli
  push  0
  push  18
  jmp isr_main
isr19:
  cli
  push  0
  push  19
  jmp isr_main
isr20:
  cli
  push  0
  push  20
  jmp isr_main
isr21:
  cli
  push  0
  push  21
  jmp isr_main
isr22:
  cli
  push  0
  push  22
  jmp isr_main
isr23:
  cli
  push  0
  push  23
  jmp isr_main
isr24:
  cli
  push  0
  push  24
  jmp isr_main
isr25:
  cli
  push  0
  push  25
  jmp isr_main
isr26:
  cli
  push  0
  push  26
  jmp isr_main
isr27:
  cli
  push  0
  push  27
  jmp isr_main
isr28:
  cli
  push  0
  push  28
  jmp isr_main
isr29:
  cli
  push  0
  push  29 
  jmp isr_main
isr30:
  cli
  push  30
  jmp isr_main
isr31:
  cli
  push  0
  push  31 
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
	
	sti
	iret
