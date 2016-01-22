# NewStickOS
(Excuse my english rip)
Remaking kernel of StickOS (old project of mine, can find it on github too).
Didn't like how stuffy I was, kept on changing this and that and I could feel claustrophobic.
New kernel is being made now.
Changes are going to be made to bootloader and boot2.

Soon to come in boot2:
  Getting memory map.
  Better determining if a20 is enabled.
  
Soon to come in bootloader:
  Clean up some of the useless code.
  
-------------------------------------------------------------------------------------------------------------------------

#NewStickOS 2.4 (0.2.4) 
Thu, Jan 21, 2016

Recently added (from 4 month period)

-Memory map code is made, but has not been fully tested
-Pit code possible finish within 1~4 months
-Vga code possible finish after Pit is settled plus 1~4 months
-No where finished with kernel, usermode interface probably in atleast one year or more
-Possible replace code of Pit with HPET usage, maybe after os is setteled
-Reading docs about the APIC timer, seems interesting
-The OS has been moved from windows development to ubuntu, well most
-Cross-compiler: (same as before) i686-elf
