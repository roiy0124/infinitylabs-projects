#include <cassert> // for assert
#include <cstddef> //for using size_t

// WS: Pointers - Part 2 
// Name: Roie Itzhakov
// Reviewer: Daniel Stern
// Date: 04/08/2026

int IsPalindrome(const char* str)
{
    assert(NULL != str);
    
    if (*str == '\0')
        return 1;
    
    const char* end = str;
    
    while(*(end + 1) != '\0')
        end++;
    
    while(str < end)
    {
        if(*end != *str)
            return 0;
        str++;
        end--;
    }
    return 1;
}

std::size_t StrLen(const char* start)
{
    assert(NULL != start);
    const char* end = start;

    while(*end != '\0')
        ++end;
        
    return end - start;   
}

static char* RmSpaces(char* read_i)
{
    while(*read_i != '\0' && *read_i == ' ' || *read_i == '\t')
        read_i++;
    return read_i;
}

void SpaceReview(char* str)
{
    assert(NULL != str);
    char* write_i = str; 
    char* read_i = str;
    
    read_i = RmSpaces(read_i);
    
    while (*read_i != '\0')
    {
        if (*read_i == ' ' || *read_i == '\t')
        {
           *write_i = *read_i;
            write_i++;
            read_i = RmSpaces(read_i);
        }
        
        else
        
        {
            *write_i = *read_i;
            write_i++;
            read_i++;
        }

    }
    *write_i = '\0';
}


