#include <stdint.h>
#include "../include/String.h"


int32_t string_find(const char* str, const char* cocstr, uint32_t start, uint32_t finish){
	const uint32_t size = string_len(str);
	//const uint32_t csize = string_len(cocstr);
	
	int32_t temp = STRING_NOMATCH;
	if (finish == STRING_END || finish > size)
		finish = size;
	
	
	
	char* ptr = (char*)(str + start);
	char* ptr2 = (char*)(cocstr);
	
	while (start < finish && (*ptr != 0 || *ptr2 != 0)) {
		if (*ptr == *ptr2){
			if (temp == STRING_NOMATCH)
				temp = start;
		}else{
			temp = STRING_NOMATCH;
		}
		start++;
	}
	
	return temp;
}


uint32_t string_len(const char* str){
	uint32_t temp = 0;
	
	while (*str++ != 0){
		temp++;
	}
	return temp;
}