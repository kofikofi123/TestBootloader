
ENTRY(kernel_main)
OUTPUT("/home/ubuntu/workspace/NewStickOS/bin/kernel.bin")

SECTIONS 
{
	. = 0x10000;
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
	.bss : { *(.bss) }
}
