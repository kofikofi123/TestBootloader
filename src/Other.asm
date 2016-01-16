BITS 32
section .text
	global flush_gdt
	global get_registers
	

get_registers:
    mov [.ebp_buffer], ebp
    mov [.esp_buffer], esp
    push ebp
      
    
    mov ebp, esp 
    mov esp, [ebp + 8]
    mov ebp, [.ebp_buffer] 
    
    pushfd 
    push eax 
    push ecx 
    push edx 
    push ebx 
    push dword [.esp_buffer]
    push dword [.ebp_buffer]
    push esi 
    push edi
    push ds 
    push es 
    push gs 
    push fs 
    push ss 
    push cs 
    
    jmp .done 
.esp_buffer: dw 0
.ebp_buffer dw 0
.done:
    mov esp, dword [.esp_buffer]
    mov ebp, dword [.ebp_buffer]
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