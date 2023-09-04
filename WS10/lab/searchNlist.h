
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"

namespace sdds
{
    template <typename T, typename K>
    bool search(Collection<T> &collection, const T *arr, int nElements, const K &key)
    {
        // Search Function template Requirements:
        //
        // 1) The first argument "collection" which is a refrence of template Collection
        //    must be compatible with the Collection template defined in "Collection.h" file.
        //
        // 2) There should be an overload operator "==" for the "K" used as another template parameter.
        //
        // 3) There must be a correct and compatible version of add function available to add
        //    the new key into the collection.
        bool flag = false;
        for (int i = 0; i < nElements; i++)
        {
            if (arr[i] == key)
            {
                collection.add(arr[i]);
                flag = true;
            }
        }

        return flag;
    }
    template <typename T>
    void listArrayElements(const char *title, const T *objArr, int nElements)
    {
        // listArrayElements function template Requirements:

        // The 'T' used as the template parameter should be compatible with the elements of
        // the array and should support the "<<" operator for output to std::cout.
        std::cout << title << std::endl;
        int i = 0;
        while (i < nElements)
        {
                std::cout << i + 1 << ": " << objArr[i] << std::endl;
                i++;
            
        }
    }
}

#endif