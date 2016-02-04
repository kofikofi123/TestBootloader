#include "../include/Memmap.h"
#include "../include/Memtools.h"
#include "../include/Other.h"
#include <stdint.h>

struct Memrange new_memory_map[64];


void sort_mapped_memory(void){
	struct registers_t registers;
	//get_registers(&registers);
	/*
	uint8_t *pointer = (uint8_t*)(registers.esi);
	char* test = "MEMCHECK_TEST_LOOK_HERE!!!"; //Ill look in memory
	uint32_t table_size = (*(uint32_t*)pointer);
	pointer += 4;
	
	char* test1 = "CHECKPOINT2";
	memcpy(&new_memory_map, pointer, table_size * 24);*/
	
	
}
//{}
//a = {3, 4, 1, 2}
//new = {}
//temp = 0
//for x = 1, #a do 
//	temp = a[x]
//	for y = x, #a do 
//		if (a[y] > temp) then 
//			temp = a[y]
//		end 
//	end 
//end