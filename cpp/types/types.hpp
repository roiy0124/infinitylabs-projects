#ifndef ILRD_SW181_TYPES_HPP
#define ILRD_SW181_TYPES_HPP

#include <cstdio> // sprintf
#include <iostream> // cout
#include <cstring> // strlen

namespace ilrd 
{
#define MAX2(a,  b)  ((a) > (b) ? (a) : (b)) 
#define MAX3(a, b, c)  (MAX2(MAX2(a, b), c))
#define SIZEOF_VAR(var) ((char*)(&(var) + 1) - (char*)&(var))
#define SIZEOF_TYPE(type) ((char*)((type*)0 + 1) - (char*)((type*)0))


enum Types
{
INT,
FLOAT,
STRING
};

void Ex1();
}
#endif
