BITS 32
section .text
	global flush_gdt
	global get_registers
	

get_registers:
    mov [get_registers_ebp_buffer], ebp
    mov [get_registers_esp_buffer], esp
    
    
    mov ebp, esp 
    mov esp, [ebp + 8]
    mov ebp, [get_registers_ebp_buffer] 
    
    add esp, 48
    pushfd 
    push eax 
    push ecx 
    push edx 
    push ebx 
    push dword [get_registers_esp_buffer]
    push dword [get_registers_ebp_buffer]
    push esi 
    push edi
    push ds 
    push es 
    push gs 
    push fs 
    push ss 
    push cs 
    
    jmp .done
.done:
    mov esp, dword [get_registers_esp_buffer]
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
	
section .data
    get_registers_ebp_buffer dd 0 
    get_registers_esp_buffer dd 0 
    