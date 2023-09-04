
#include "cstring.h"
namespace sdds
{
    void strCpy(char *des, const char *src)
    {
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0'; // Setting the null terminator('\0') at the end of the DESTINATION string
    }
    int strLen(const char *s)
    {
        int i = 0;
        while (s[i] != '\0') // if the character at i index is not null then i am counting it in the length
        {
            i++;
        }
        return i;
    }
    void strCat(char *dest, const char *src)
    {
        while (*dest != '\0') // Iterating the given DESTINATION string(char array) until find null terminator('\0')
        {
            dest++;
        }
        // After the execution of above loop the pointer is now at the end of destination string

        while (*src != '\0') // Iterating the given SOURCE string(char array) until find null terminator('\0')
        {
            *dest = *src; // The value of *dest here is pointing to the last character of the DESTINATION string and
                          // *src is the first character of the SOURCE string
            dest++;
            src++;
        }
        *dest = '\0'; // Setting the null terminator('\0') at the end of the DESTINATION string
    }
}