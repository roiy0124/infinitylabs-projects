// WS: User Defined Types 1
// Name: Roie Itzhakov
// Reviewer: Dudi Chen
// Date: 17/08/2026

#include <cstdio> // sprintf
#include <iostream> // cout
#include <cstring> // strlen

#include "types.hpp" // Ex1

using namespace std;
using namespace ilrd;

namespace ilrd
{
struct ElemFuncs
{
    void (*add) (void*,int);
    void (*print)(void*);
    void (*cleanup)(void*);
};

struct GenArr
{
    void* data;
    const ElemFuncs* func;
};

static int NumLen(int value)
{
int counter = 0;
while(value!=0)
{
    value/= 10;
    ++counter; 
}
    return counter;
}

static void AddInt(void* data, int value)
{
    int* ptr = static_cast<int*>(data);
    *ptr += value;
}

static void AddFloat(void* data, int value)
{
    float* ptr = static_cast<float*>(data);
    
    *ptr += value;
}

static void AddString(void* data, int value)
{   
    char** ptr = static_cast<char**>(data);
    char* res = new (nothrow) char[strlen(*ptr) + NumLen(value) + 1];
    sprintf(res,"%s%d", *ptr, value);
    delete[] *ptr;
    *ptr = res;      
}

static void PrintInt(void* data)
{
    int* ptr = static_cast<int*>(data);
    cout << *ptr << endl; 
}

static void PrintFloat(void* data)
{
    float* ptr = static_cast<float*>(data);
    cout << *ptr << endl; 
}

static void PrintString(void* data)
{
    char** ptr = static_cast<char**>(data);
    cout << *ptr << endl;
}

static void CleanupInt(void*)    { }
static void CleanupFloat(void*)  { }  

static void CleanupString(void* data)
{ 
    char** ptr = static_cast<char**>(data);
    delete[] *ptr;
}

void Ex1()
{
    const int ELEMENTS_COUNT_TYPES = 3;
    ElemFuncs elems[ELEMENTS_COUNT_TYPES];
    
    GenArr arr[3];
    int i = 10;
    float f = 3.1415;
    char* s = new (nothrow) char[9];
    
    elems[INT].add = AddInt;
    elems[INT].print = PrintInt;
    elems[INT].cleanup = CleanupInt;
    
    elems[FLOAT].add = AddFloat;
    elems[FLOAT].print = PrintFloat;
    elems[FLOAT].cleanup = CleanupFloat;

    elems[STRING].add = AddString;
    elems[STRING].print = PrintString;
    elems[STRING].cleanup = CleanupString;
    
    
    strcpy(s, "testing!");
    arr[0].data = &i;
    arr[1].data = &f;
    arr[2].data = &s;
    
    for(int j  = 0; j < 3; j++)
    {
        arr[j].func = &elems[j];
        arr[j].func->print(arr[j].data);
        arr[j].func->add(arr[j].data, 10);
        arr[j].func->print(arr[j].data);
    }

    for(int j = 0; j < 3; j++)
    {  
        arr[j].func->cleanup(arr[j].data);    
    }   
    
}
}
