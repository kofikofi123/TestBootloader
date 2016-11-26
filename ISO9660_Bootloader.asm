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
    
    mov [boot_drive], dl
    ;Check if extended 0x13 funcctions are supported
    mov ah, 0x41
    mov bx, 0x55AA
    int 0x13

    jc .supported ;(
    lea si, [error_message2]
    call Print_string
    jmp 

.supported:
    mov cl, 5
    ;reset drive
.reset_drive_begin:
    call Reset_drive 
    jnc .start_parsing
    loop .reset_drive_begin
    lea si, [error_message1]
    call Print_string
    jmp looper
.start_parsing:
    ;nothing still yet
looper:
    jmp looper
    
;variables
bdrive: db 0

error_message1: db "Unable to reset boot drive.", 0
error_message2: db "Extended bios interrupts not supported. Try again or use different bootloader", 0

test_message1: db "tester imager", 0
kernel_file_name db "STICK.BIN", 0 
boot_setting_file_name db ""
times 510-($-$$) db 0
db 0x55
db 0xAA
