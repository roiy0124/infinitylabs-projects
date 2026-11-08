#ifndef ILRD_SW181_BITWISE_HPP
#define ILRD_SW181_BITWISE_HPP

#include <cstddef>

namespace ilrd
{
long Pow2(unsigned int x, unsigned int y);
bool IsPow2Loop(unsigned int n);
bool IsPow2(unsigned int n);
int Increment(int n);
void PrintSet3(unsigned int arr[], size_t size);
unsigned int ByteMirrorLoop(unsigned int n);
unsigned int ByteMirror(unsigned int n);
bool Check2And6(unsigned char c);
bool Check2Or6(unsigned char c);
unsigned char Swap3And5(unsigned char c);
unsigned int Closest16(unsigned int n);
void Swap(int* a, int* b);
int CountSetBitsLoop(int n);
int CountSetBits(int n);
void PrintFloatBits(float n);
}

#endif


