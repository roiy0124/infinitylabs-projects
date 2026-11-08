#include <cstddef> //for using size_t
#include <iostream> // for using cout
#include <cstring> // for using strlen
#include <cctype> // for using tolower
#include <cassert> // for using assert
#include "arrays.hpp"

// WS: Arrays & Pointer to Pointer (C++)
// Name: Roie Itzhakov
// Reviewer: 
// Date: 05/08/2026

using namespace std;
namespace ilrd
{

void SumMatrix(int** mat, size_t rows, size_t cols, int* result)
{
    assert(NULL != mat && rows > 0 && cols > 0);
    
    size_t row, col;
    
    for(row = 0; row < rows; row++)
    {
        result[row] = 0;
        
        for(col = 0; col < cols; col++)
        {
            result[row] += mat[row][col];
        }
    }
}


size_t Josephus(size_t size)
{
    assert(size > 0);
    
    size_t* soldiers = new (nothrow) size_t [size];
    
    assert(NULL != soldiers);
    
    bool is_to_kill = true;
    
    size_t curr;
    
    for(curr=0; curr < size; curr++)
    {
        soldiers[curr] = (curr + 1) % size;
    }
    
    curr = 0;
    
    while (soldiers[curr] != curr)
    {
        
        if(is_to_kill == true)
        {
            soldiers[curr] = soldiers[soldiers[curr]];
            is_to_kill = false;
        }
        else
        {
            is_to_kill = true;
            curr = soldiers[curr];
        }
            }
    
    int res = soldiers[curr];
    delete[] soldiers;
    return res + 1;
}


void PrintDataTypeSize()
{
    std::cout << "void: " << 0 << " Bytes" << std::endl;
    
    std::cout << "bool: " << sizeof(bool) << " Bytes" << std::endl;
    
    std::cout << "short: " << sizeof(short) << " Bytes" << std::endl;    
    
    std::cout << "int: " << sizeof(int) << " Bytes" << std::endl;
    
    std::cout << "float: " << sizeof(float) << " Bytes" << std::endl;
    
    std::cout << "long: " << sizeof(long) << " Bytes" << std::endl;
    
    std::cout << "double: " << sizeof(double) << " Bytes" << std::endl;
    
    std::cout << "long double: " << sizeof(long double) << " Bytes" << std::endl;
    
    std::cout << "char: " << sizeof(char) << " Bytes" << std::endl;
    
    std::cout << "wchar_t: " << sizeof(wchar_t) << " Bytes" << std::endl;
}

void CopyPrintEnv(char** envp)
{   
    assert(NULL != envp);
    
    size_t size = 0;
    
    int row = 0;
    
    int col = 0;
    
    while (envp[size] != NULL)
    {
        ++size;
    }
    
    char** res = new (nothrow) char*[size + 1];
    
    assert(NULL != res);
    
    while (envp[row] != NULL)
    {
        res[row] = new (nothrow) char[strlen(envp[row]) + 1];
        
        assert(NULL != res[row]);
        
        while(envp[row][col] != '\0')
        {
            res[row][col] = tolower(envp[row][col]);
            ++col;
        }
        res[row][col] = '\0';
        col = 0;
        cout << res[row] << endl;
        ++row;
    }
    res[row] = NULL;
    row = 0;
    while(res[row] != NULL)
    {
        delete[] res[row];
        ++row;
    }
    delete[] res;
}
}


