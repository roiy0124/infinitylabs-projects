#include <cstddef>
#include <iostream>
#include <cassert>
#include "pointers1.hpp"

void Swap(int* x, int* y)
{
    size_t temp = *x;
    *x = *y;
    *y = temp;
}

void SwapTwoSize(size_t* x, size_t* y)
{
    size_t temp = *x;
    *x = *y;
    *y = temp;
}

void SwapTwoSizeP(size_t** x, size_t** y)
{
    SwapTwoSize((size_t*)x, (size_t*)y);
}

void CopyArr(int* dest, int* src, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++)
        dest[i] = src[i];
}


std::size_t StrLen(const char* start)
{
    assert(start != nullptr);
    const char* end = start;

    while(*end != '\0')
        ++end;
        
    return end - start;   
}


int StrCmp (const char* str1, const char* str2)
{
    assert(str1 != nullptr && str2 != nullptr);
    while(*str1 != '\0' && *str1 == *str2)
{
    ++str1;
    ++str2;
}
    return *str1 - *str2;
}


