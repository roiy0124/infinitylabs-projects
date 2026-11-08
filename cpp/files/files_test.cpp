#include <cassert> // assert
#include <cstdio> // fopen
#include <iostream> // cout

#include "files.hpp" //FileLogger
using namespace ilrd;
int main()
{
    const char* path = "/home/roieitzhakov/git/cpp/files/logger.md";
    FileLogger(path);
    return SUCCESS;
    
}
