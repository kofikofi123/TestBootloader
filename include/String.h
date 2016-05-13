// The goal of this file is to provide high-performance string manipulation
// tools.

#ifndef _STRING_H
#define _STRING_H

#include <stdint.h>

#define STRING_END -1
#define STRING_NOMATCH -2

/**
 * Search for a substring within a range.
 * @param source The source string
 * @param substring The sub string to find
 * @param start The beginning of the source to search
 * @param finish The end of the source to search or STRING_END
 * @see STRING_END
 * @see STRING_NOMATCH
 * @return The location that substring was first found or STRING_NOMATCH
 */
int32_t string_find_range(const char *source, const char *substring,
        intptr_t start, intptr_t finish);

/**
 * Search for a substring within a source string
 * @param source The source string
 * @param substring The substring to find
 * @see STRING_NOMATCH
 * @return The location that substring was first found or STRING_NOMATCH
 */
int32_t string_find(const char *source, const char *substr);

/**
 * Compares two strings
 * @param a The first string
 * @param b The second string
 * @return 1 if the strings were the same, otherwise 0.
 */
int32_t string_compare(const char *a, const char *b);

/**
 * Gets the length of a source string
 * @param source The string to get the length of
 * @return The length of source
 */
uint32_t string_len(const char *source);

#endif
