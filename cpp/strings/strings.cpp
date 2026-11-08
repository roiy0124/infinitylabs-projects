#include <cassert> // for assert
#include <cstring> // for using tolower func
#include <cstddef> // for using size_t
#include "pointers2.hpp"

// WS: Pointers - Part 2 
// Name: Roie Itzhakov
// Reviewer: Daniel Stern
// Date: 04/08/2026


static std::size_t StrLen(const char* str)
{
    assert(str != NULL);
    const char* end = str;

    while(*end != '\0')
        ++end;
        
    return end - str;   
}

char* StrCpy(char* dest, const char* src)
{
    assert(src != NULL && dest != NULL); 
    char* temp = dest;
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
return temp;
}

char* StrnCpy(char* dest, const char* src, std::size_t count)
{
    assert(src != NULL && dest != NULL); 
    char* temp = dest;
    while(count > 0)
    {
        if(*src != '\0')
        {
            *dest = *src;
            ++src;
        }
        else
            *dest = '\0';
        ++dest;
        
        --count;
    }
    return temp;
}

int StrnCmp(const char* lhs, const char* rhs, std::size_t count)
{

    assert(lhs != NULL && rhs != NULL);
    while(count > 0 && *lhs != '\0' && *lhs == *rhs)
    {
        ++lhs;
        ++rhs;
        --count;

    }
    
    return *lhs - *rhs;
}

int StrCaseCmp(const char* s1, const char* s2)
{
    assert(s1 != NULL && s2 != NULL);
    while(std::tolower(*s1) != '\0' && std::tolower(*s1) == std::tolower(*s2))
{
    ++s1;
    ++s2;
}
    return std::tolower(*s1) - std::tolower(*s2);
}

char* StrChr(char* str, int ch)
{
    assert(str != NULL);
    while(*str != '\0')
    {
        if(*str == ch)
            return str;
        str++;
    
    }
    if(*str == ch)
        return str;
    return NULL;
}

char* StrDup(const char* src)
{
    std::size_t len = StrLen(src);
    
    char* dest = new char[len + 1];
    char* temp_dest = dest;
    while(*src != '\0')
    {
        *temp_dest = *src;
        temp_dest++;
        src++;
    }
    *temp_dest = '\0';
    return dest;
}
char* StrCat(char* dest, const char* src)
{
    std::size_t lsrc = StrLen(src);
    std::size_t ldest = StrLen(dest);
    std::size_t i = 0;
    
    for(i=0;i<lsrc;i++)
        dest[ldest + i] = src[i];
    dest[ldest + lsrc] = '\0';
    return dest;
}


char* StrnCat(char* dest, const char* src, std::size_t count)
{   
    std::size_t ldest = StrLen(dest);
    std::size_t i = 0;
    
    
    while (i < count && src[i] != '\0')
    {
        dest[ldest + i] = src[i];
        ++i;
    }
    dest[ldest + i] = '\0';
    return dest;
}

std::size_t StrSpn(const char* dest, const char* src)
{
    const char* tmp_src;
    std::size_t len = 0;
    while(*dest != '\0')
    {
        tmp_src = src;
        while (*tmp_src != '\0' && *tmp_src != *dest)
        {
            if (*tmp_src == *dest)
                tmp_src++;
        }
            if (*tmp_src == '\0')
                return len;
            len++;
            dest++;
        }
        return len;
    }
    

    
    
    
    
    
    
    
