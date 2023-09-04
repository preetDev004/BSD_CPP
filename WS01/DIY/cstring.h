
#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds
{
    // Copies the source character string into the destination.
    void strCpy(char *des, const char *src);

    // Copies the source character string into the destination up to "count"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "count".
    void strnCpy(char *des, const char *src, int count);

    // Compares lexicographically two C-strings.
    // - returns 0 if they are the same
    // - return > 0 if s1 > s2
    // - return < 0 if s1 < s2
    int strCmp(const char *s1, const char *s2);

    // Compares lexicographically the first "count" characters of two C-strings.
    // - returns 0 if they are the same
    // - return > 0 if s1 > s2
    // - return < 0 if s1 < s2
    int strnCmp(const char *s1, const char *s2, int count);

    // Finds the size of a C-string.
    // - returns the number of characters in "s".
    int strLen(const char *s);

    // Search if a string is a substring in another string.
    // - returns the address of first occurance of "needle" in "haystack".
    // - returns nullptr if no match is found.
    const char *strStr(const char *haystack, const char *needle);

    // Concantinates "src" C-string to the end of "dest".
    void strCat(char *dest, const char *src);
}
#endif
