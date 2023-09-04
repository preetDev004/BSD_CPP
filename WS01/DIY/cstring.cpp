
#include <iostream>
#include <cstdio>
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
    void strnCpy(char *des, const char *src, int count)
    {
        for (int i = 0; i < count; i++)
        {
            if (*src != '\0')
            {
                *des = *src;
                des++;
                src++;
            }
            else{
                *des = '\0';
            }
        }
    }
    int strCmp(const char *s1, const char *s2)
    {
        while (*s1 == *s2) // Compares the first charaters of both strings
        {
            // if condition becomes true then we check for next character in the string
            s1++;
            s2++;
        }

        return (*s1 - *s2); // subtracting ASCII code if its negative then  s1 is less then s2 and vise versa and
                            // if it returns 0 then both strings are same.
    }
    int strnCmp(const char *s1, const char *s2, int count)
    {
        int i;
        for (i = 0; i < count; i++)
        {
            if (s1[i] != s2[i])
                return s1[i] - s2[i];

            if (s1[i] == '\0') // if we reach the end of string before the numbers of charcter we have to compare.
                return 0;
        }

        return 0;
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
    const char *strStr(const char *haystack, const char *needle)
    {
        while (*haystack != '\0')
        {
            const char *s1 = haystack;
            const char *s2 = needle;
            while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
            {
                s1++;
                s2++;
            }
            if (*s2 == '\0') // if we successfully iterate the needle comparision this condition becomes true hand we get the sub-string
                return haystack;

            haystack++; // iterating again from the next character in the main string.
        }
        return nullptr; // no match found for sub-string
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