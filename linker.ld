
ENTRY(kernel_main)
OUTPUT("C:/OS/bin/kernel.bin")

SECTIONS 
{
	. = 0x10000;
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
	.bss : { *(.bss) }
}
