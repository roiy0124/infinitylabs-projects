
// WS : Atoi 
// Name : Roie Itzhakov
// Reviewer : Yehonatan Tamir
// Date : 27.06.26

#include <string> // string instance
#include <iostream> // cout
#include "atoi.hpp"

using namespace std;

namespace ilrd
{

// convert a number to be presented as a string 
string Itos(int n)
{
    if (n == 0) 
    {
        return "0";
    }
    
    string str("");
    
    while(n != 0) 
    {
        str.insert(str.begin(), (n % 10) + '0');
        n /= 10;
    }
    return str;
}

// convert number presented as a string to a real number
int Stoi10(const string& str)
{
    return Stoi(10, str);
}
    
int Stoi10(const char* str)
{
    if(NULL == str)
    {
        return -1;
    }
    
    int res = 0;
    
    while (*str != '\0')
    {
        res *= 10;
        res += *str - '0';
        ++str;
    }
    return res;
}

// converts a given string to an integer in a given base.
int Stoi(int base, const string& str)
{
    if(base < 2 || base > 36)
    {
        return -1;
    }
    const char* ptr = str.c_str(); 
    int res =0;
    int digit;
    while (*ptr != '\0')
    {   
        if (*ptr >= '0' && *ptr <= '9')  
            digit = *ptr - '0';   
        else   
            digit = *ptr - 'A' + 10;

        res *= base;    
        res += digit; 
        ++ptr; 
    }
    return res;
}

// prints the characters that appears in 'arr1' and 'arr2' but not in 'arr3'
void Print3arrs(char arr1[], int size1, char arr2[], int size2, char arr3[], int size3)
{
    int res[256];
    for(int i = 0; i < 256; ++i)
    {
        res[i] = 0;
    }
    
    for(int i = 0; i < size1; i++)
    {
        res[static_cast<unsigned char>(arr1[i])] |= 1;
    }
    
    for(int i = 0; i < size2; i++)
    {
        res[static_cast<unsigned char>(arr2[i])] |= 2;
    }
    
    for(int i = 0; i < size3; i++)
    {
        res[static_cast<unsigned char>(arr3[i])] |= 4;
    }
    
    for(int i = 0; i < 256; ++i)
    {
        if(res[i] == 3)
        {
            cout << static_cast<char>(i) << " ";
        }
    }
    cout << endl;
}
//checks if the hosting system is little endian or not
bool IsLittleEndian()
{
    unsigned int x = 1;  
    unsigned char* firstByte = reinterpret_cast<unsigned char*>(&x);
    return (*firstByte == 1);
}

}


 
