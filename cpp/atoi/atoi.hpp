#ifndef ILRD_SW181_ATOI_HPP
#define ILRD_SW181_ATOI_HPP

#include <string>

#define MyLittleIndian (*reinterpret_cast<const unsigned char*>(&(i)) == 1)

namespace ilrd
{
string Itos(int n);
int Stoi(int base, string& str);
int Stoi10(const string& str);
int Stoi10(const char* str);
    
void Print3arrs(char arr1[], int size1, char arr2[], int size2, char arr3[], int size3);

    
bool IsLittleIndian();
    

}//ns

#endif
