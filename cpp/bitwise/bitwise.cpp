//WS: Bitwise Operations (C++)
//Name: Roie Itzhakov
//Reviewer: Erik Idelchik
//Date: 12/08/2026

#include <iostream> // cout
#include <cstddef> // size_t
#include <cstring> // memcpy
#include <cassert> // assert

#include "bitwise.hpp"

using namespace std;

namespace ilrd
{
long Pow2(unsigned int x, unsigned int y)
{
    return (static_cast<long>(x) << y);
}

bool IsPow2Loop(unsigned int num)
{
    unsigned int mask = 1;
    unsigned int counter = 0;
    for(int i = 0;i < 32; i++)
    {
        if(num & mask)
        {
            ++counter;
        }
        mask <<= 1;
    }
    
    return counter == 1;
    }

bool IsPow2(unsigned int num)
{
    return (0 != num) && (num & (num - 1)) == 0;
}

int Increment(int n)
{
    unsigned int mask = 1;
    while((n & mask) != 0)
    {
        n ^= mask;
        mask <<= 1;
    }
    n ^= mask;
    return n;
}

void PrintSet3(unsigned int arr[], size_t size) 
{
    unsigned int mask = 1, bcounter = 0;
    
    for(int i=0;i<size;i++)
    {
        for (size_t j = 0; j < 32; j++)
        {
            if(mask & arr[i])
            {
                ++bcounter;
            }
            mask <<= 1;
        }
        
        if(bcounter == 3)
        {
            cout << arr[i] << endl;
        }
        bcounter = 0;
        mask = 1;
    }
}

unsigned int ByteMirrorLoop(unsigned int n)
{
    unsigned int res = 0;
    unsigned int start_mask = 1;
    unsigned int end_mask = 1;
    end_mask <<= 31;
    
    while(0 != end_mask)
    {
        if(n & end_mask)
        {
            res ^= start_mask;
        }
        end_mask >>= 1;
        start_mask <<= 1;
    }
    return res;
}

unsigned int ByteMirror(unsigned int n) 
{
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
    n = (n >> 16) | (n << 16);
    
    return n;
}

bool Check2And6(unsigned char c)
{
    return ((c & 2) && (c & 32));
}

bool Check2Or6(unsigned char c)
{
    return ((c & 2) || (c & 32));
}

unsigned char Swap3And5(unsigned char c)
{
    unsigned int bit_in3 = (c & 4) > 0;
    unsigned int bit_in5 = (c & 16) > 0;
    unsigned int diff = bit_in3 ^ bit_in5;

    c ^= (diff << 2) | (diff << 4);
    return c;
}

unsigned int Closest16(unsigned int n)
{
    int mask = 1;
    for(int i = 0; i < 4;i++)
    {
        if(n & mask)
        {
            n ^= mask;
        }
        mask <<= 1;
    }
    return n;
}

void Swap(int* a,int* b)
    {
        assert(NULL != a && NULL != b);
        if (a != b)
        {
            *a ^= *b;
            *b ^= *a;
            *a ^= *b;
        }
    }

int CountSetBitsLoop(int n) 
{
    unsigned int mask = 1;
    int counter = 0;
    for(size_t i = 0; i < 32; i++)
    {
        if(n & mask)
        {
            ++counter;
        }
        mask <<= 1;
    }
    return counter;
}

int CountSetBits(int n)
{
    unsigned int num = static_cast<unsigned int>(n);
    return ((num >> 0)  & 1) +
           ((num >> 1)  & 1) +
           ((num >> 2)  & 1) +
           ((num >> 3)  & 1) +
           ((num >> 4)  & 1) +
           ((num >> 5)  & 1) +
           ((num >> 6)  & 1) +
           ((num >> 7)  & 1) +
           ((num >> 8)  & 1) +
           ((num >> 9)  & 1) +
           ((num >> 10) & 1) +
           ((num >> 11) & 1) +
           ((num >> 12) & 1) +
           ((num >> 13) & 1) +
           ((num >> 14) & 1) +
           ((num >> 15) & 1) +
           ((num >> 16) & 1) +
           ((num >> 17) & 1) +
           ((num >> 18) & 1) +
           ((num >> 19) & 1) +
           ((num >> 20) & 1) +
           ((num >> 21) & 1) +
           ((num >> 22) & 1) +
           ((num >> 23) & 1) +
           ((num >> 24) & 1) +
           ((num >> 25) & 1) +
           ((num >> 26) & 1) +
           ((num >> 27) & 1) +
           ((num >> 28) & 1) +
           ((num >> 29) & 1) +
           ((num >> 30) & 1) +
           ((num >> 31) & 1);
}

void PrintFloatBits(float n)
{
    int arr[32];
    unsigned int num = 0;
    memcpy(&num, &n, sizeof(num));
    unsigned int mask = 1;
    for(size_t i = 0; i < 32; i++)
    {
        arr[i] = (num & mask) ? 1 : 0;
        mask <<= 1;
    }
    for(int j = 31; j >= 0; j--)
    {
        cout << arr[j];
    }
}
}
