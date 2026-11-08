#ifndef ILRD_SW181_STRINGS_HPP
#define ILRD_SW181_STRINGS_HPP

#include <cstddef>

using namespace std;
namespace ilrd
{

void SumMatrix(int** mat, size_t rows, size_t cols, int* result);

size_t Josephus(size_t size);

void PrintDataTypeSize();

void CopyPrintEnv(char** envp);

}
#endif


