;Do not test anything below, please

org 0x7C00

jmp 0x00:Main

Reset_drive:
    mov ax, 0
    int 0x13 
    ret
    
Print_string: ;we are going to use the interrupt service because I do not need to directly write to it right now
    pusha
    pushf 
    cld
    
    mov ah, 0x0E
    mov bl, 0x0F
.looper:
    lodsb
    
    or al, al 
    jz .fini
    
    int 0x10 
    jmp .looper
.fini:
    popf
    popa 
    ret

Main:
    xor ax, ax 
    mov ds, ax
    
    cli
    mov ss, ax
    mov sp, 0x7DFF
    sti 
    
    mov cl, 5
.clear_drive_begin:
    call Reset_drive 
    or ax, 1 
    jnz .start_parsing
    loop .clear_drive_begin
    lea si, [error_message1]
    call Print_string
.start_parsing:
    lea si, [test_message1]
    call Print_string
looper:
    jmp looper
    
;variables
bdrive: db 0
error_message1: db "Unable to reset boot drive.", 0
test_message1: db "tester imager", 0
times 510-($-$$) db 0
dw 0xAA55