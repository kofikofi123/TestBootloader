;Do not test anything below, please
;Warning if you do run it: I did not finish some of the operation, or even test it.
;This means it could get at places, mess something up, error
BITS 16

ORG 0x7C00

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

Read_sector:;register destroyer
    mov cx, 3
    mov [disk_packet_struct.sectors_to_read], ax 
    mov word [disk_packet_struct.read_address], di
    mov word [disk_packet_struct.read_address + 2], bx 
    mov word [disk_packet_struct.lba_address], si 

    push ds 
    push dx 
    push si 
    push ax

    xor ax, ax 
    mov ds, ax 
.begin:
    mov dl, [bdrive]
    lea si, [disk_packet_struct] ;ds should already be 0
    mov ah, 0x42
    xchg bx, bx
    int 0x13
    xchg bx, bx
    jnc .fini
    loop .begin
.fini:
    pop ax 
    pop si
    pop dx 
    pop ds
    ret

Read_file:
    ret  

Validate_sector:
    push si 
    push di 
    push cx
.compare:
    lea si, [disk_buffer + 1]
    lea di, [filesystel_validation_string]
    mov cx, 5 
    repe cmpsb
.fini:
    pop cx 
    pop di 
    pop si
    ret
    
Validate_volume_id:
    push bx 
    mov bl, byte [disk_buffer]
    cmp al, bl 
    pop bx
    ret

Main:
    xor ax, ax 
    mov ds, ax
    
    cli
    mov ss, ax
    mov sp, 0x7BFF
    sti 
    
    mov [bdrive], dl
    ;Check if extended 0x13 funcctions are supported
    mov ah, 0x41
    mov bx, 0x55AA
    mov dl, [bdrive]
    int 0x13
    jnc .supported
.not_supported: ;
    lea si, [error_message2]
    jmp .errornous
.supported: ; :(
    mov cl, 5
;reset drive
.reset_drive_begin:
    call Reset_drive 
    jnc .setup_reading
    loop .reset_drive_begin
    lea si, [error_message1]
    jmp .errornous

.setup_reading:
    mov si, 16
    push si ;may not be needed
.start_reading:
    mov ax, 1 
    mov bx, 0
    lea di, [disk_buffer]
    ;label not finished
    call Read_sector
    call Validate_sector
    je .found_begin
    lea si, [error_message3]
    jmp .errornous
.found_begin:
    pop si ;may not be needed
    mov al, 1 
    call Validate_volume_id 
    je .try_read_file
    lea si, [kernel_file_name]
.try_read_file:
    lea si, [test_message1]
    call Print_string
    jmp looper
.errornous:
    call Print_string ;si should already be loaded
looper:
    cli
.lop:
    jmp .lop

;variables
bdrive: db 0

error_message1: db "Unable to reset boot drive.", 0
error_message2: db "Extended bios interrupts not supported. Try again or use different bootloader", 0
error_message3: db "Invalid filesystem", 0

test_message1: db "tester imager", 0
kernel_file_name db "STICK.BIN", 0 
boot_setting_file_name db ""
filesystel_validation_string db "CD001", 0

disk_packet_struct:
    db 0x10
    db 0 
.sectors_to_read:
    dw 0
.read_address:
    dw 0
    dw 0
.lba_address:
    dq 0

times 510-($-$$) db 0
db 0x55
db 0xAA
disk_buffer: times 2048 db 0
