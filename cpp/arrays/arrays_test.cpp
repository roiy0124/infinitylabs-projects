#include <cstddef>
#include <iostream>
#include "arrays.hpp"

using namespace std;
using namespace ilrd;

int main(int argc, char** envp)

{
    int i,j;
    size_t s;
    int** mat = new int* [10];
    int* result = new int[10];
    for(i=0;i<10;i++)
    {
        mat[i] = new int [10];
    }
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
         mat[i][j] = i + j;
        }
    }
    SumMatrix(mat, 10, 10, result);
    for(i=0;i<10;i++)
    {
        
        cout << result[i] <<endl;
    }
    
    CopyPrintEnv(envp);
    PrintDataTypeSize();
    for(s=0;s<15;s++)
        cout << Josephus(s) << endl;
    cout << argc << endl;
    return 0;
}
