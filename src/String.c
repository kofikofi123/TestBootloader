#include "../include/String.h"

int32_t string_find_range(const char *source, const char *substr,
	intptr_t start, intptr_t finish)
{
    if (finish == STRING_END)
    {
        finish = INTPTR_MAX;
    }
    else
    {
        finish += (intptr_t)source;
    }
    char *caSource = (char*)(source+start), *caSubstr = (char*)substr;
    char marker;
    char subFirstLetter = *caSubstr;
    while ((marker = *caSource) != 0 && (intptr_t)caSource <= finish)
    {
        if (marker == subFirstLetter)
        {
            int i;
            for (i = 0; caSubstr[i] != 0 && caSource[i] != 0; ++i)
            {
                if (caSubstr[i] != caSource[i])
                {
                    break;
                }
            }
            if (caSubstr[i] == 0)
            {
                if ((intptr_t)caSource <= finish)
                {
                    return (int32_t)(caSource-source);
                }
            }
        }
        ++caSource;
    }
    return STRING_NOMATCH;
}

int32_t string_compare(const char *a, const char *b)
{
    char *caA = (char*)a, *caB = (char*)b;
    while (*caA != 0 && *caA++ == *caB++);
    return (*caA == 0 && *caB == 0) ? 1 : 0;
}

int32_t string_find(const char *source, const char *substr)
{
    char *caSource = (char*)source, *caSubstr = (char*)substr;
    char marker;
    char subFirstLetter = *caSubstr;
    while ((marker = *caSource) != 0)
    {
        if (marker == subFirstLetter)
        {
            int i;
            for (i = 1; caSubstr[i] != 0 && caSource[i] != 0; ++i)
            {
                if (caSubstr[i] != caSource[i])
                {
                    break;
                }
            }
            if (caSubstr[i] == 0)
            {
                return caSource-source;
            }
        }
        ++caSource;
    }
    return STRING_NOMATCH;
}

uint32_t string_len(const char* str)
{
	char* temp = (char*)str;
	while (*temp != 0){
		++temp;
	}
	return temp-str;
}
