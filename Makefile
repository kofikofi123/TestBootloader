Include=include/
Sources=src/

binfolder=bin/
imagefolder=image/
buildfolder=build/
libfolder=lib/
asmfiles=$(Sources)/*.asm
qemu="C:/Program Files (x86)/QemuManager/media"

CC=i686-elf-gcc
LD=i686-elf-ld
OBJCOPY=i686-elf-objcopy
AR=i686-elf-ar
NASM=nasm


CFLAGS=-nostdlib -ffreestanding -std=c99 -Wall -masm=intel


main: boot sources
	@$(CC) $(CFLAGS) -c kernel.c -o kernel.o 
	@$(LD) -T linker.ld kernel.o $(buildfolder)/*.o
	@$(OBJCOPY) -O binary $(binfolder)/kernel.bin $(binfolder)/kernel.bin 
	@echo Finished main rule

boot:
	@$(NASM) -f bin bootstrap.asm -o $(binfolder)/boot.img
	@$(NASM) -f bin boot2.asm -o $(binfolder)/boot2.bin 
	@echo Finished boot rule
	
sources:
	@$(CC) $(CFLAGS) -c $(Sources)/*.c
	for f in $(Sources)/*.asm; \
	do \
		nasm -f elf $$f; \
	done;
	
	@mv $(Sources)/*.o $(buildfolder)
	@mv *.o $(buildfolder)
	@echo Finished sources rule 
	
clean:
	@rm *.o
	@rm $(buildfolder)/*.o
	@rm $(binfolder)/*.bin
	@echo Finished clean rule
	
qemu_moveimage:
	@cp $(imagefolder)/offical.iso $(qemu)
	
