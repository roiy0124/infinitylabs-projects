//WS: Files (C-style, in C++)
//Name: Roie Itzhakov
//Reviewer: Dov Remes
//Date: 12/08/2026

#include <cassert> // assert
#include <cstdio> // fopen
#include <iostream> // cout
#include <cstdlib> // exit

#include "files.hpp" //FileLogger

using namespace std;
namespace ilrd
{

static int ReturnTrue(const char*, const char*)
{
    return SUCCESS;
}

static Status LogAppend(const char* path, const char* new_line)
{
    FILE* file = fopen(path, "a");
    
    if(NULL == file)
    {
        return ALLOCATION_FAILED;
    }
    
    
    if (EOF == fputs(new_line, file))
    {
        fclose(file);
        return FILE_WRITE_FAILED;
    }
    fclose(file);
    return SUCCESS;
}

static Status RemoveFile(const char* path, const char*)
{
    if(SUCCESS != remove(path))
    {
        return FILE_DELETE_FAILED;
    }
    return SUCCESS;
}

static Status FirstLineInsert(const char* path, const char* new_line)
{
    const char* temp_name = "temp.txt";
    FILE* src = fopen(path, "r");
    FILE* temp = fopen(temp_name, "w");
    char buf[256];
    
    if (NULL == src || NULL == temp) 
    {
        return FILE_READ_FAILED; 
    }
    
    ++new_line;
    fputs(new_line, temp);
    
    while (fgets(buf, 256, src) != NULL)
    {
        if (EOF == fputs(buf, temp))
        {
        return FILE_WRITE_FAILED;
        }
    }
    
    fclose(temp);
    fclose(src);
    
    if (0 != remove(path)) 
    { 
    return FILE_DELETE_FAILED; 
    }
    
    if(SUCCESS != rename(temp_name, path))
    {
        return FILE_RENAME_FAILED;
    }
    return SUCCESS;
}

static Status CountLines(const char* path, const char*)
{   
    FILE* file = fopen(path, "r");
    if (NULL == file) 
    { 
        return FILE_READ_FAILED; 
    }
    char buf[256];
    size_t lines_c = 0;
    
    while (fgets(buf, 256, file) != NULL)
    {
        ++lines_c;
    }
    
    cout << "the number of lines: " << lines_c << endl;
    fclose(file);
    return SUCCESS;
}

static Status ExitProgram(const char*, const char*)
{   
    exit(0);
    return SUCCESS;
}

static int CompareFirstLetter(const char* chr1, const char* chr2)
{
    if(*chr1 != *chr2)
        {
            return -1;
        }
    return SUCCESS;
}

static int CompareStrings(const char* str1, const char* str2)
{
    while(*str1 != '\0')
    {
        if(*str1 != *str2)
        {
            return -1;
        }
        ++str1;
        ++str2;
    }
    return SUCCESS;
}

void FileLogger(const char* path)
{
    char* buf = new char[256];
    
    FuncHandler* handler = new FuncHandler[5];
    handler[0] = {"<", FirstLineInsert, CompareFirstLetter};
    handler[1] = {"-remove", RemoveFile, CompareStrings};
    handler[2] = {"-count", CountLines, CompareStrings};
    handler[3] = {"-exit", ExitProgram, CompareStrings};
    handler[4] = {"", LogAppend, ReturnTrue};
    
    while(true)
    { 
        cout << "please enter a line:" << endl;
        if (NULL == fgets(buf, 256, stdin)) 
        { 
            break; 
        }
        for(int i = 0; i < 5; i++)
        {
            if(handler[i].compare(handler[i].str, buf) == SUCCESS)
            {
                handler[i].operation(path, buf);
                break;
            }
        }
    }
    delete[] buf;
    delete[] handler;
}


// Ex1
static void Print(int num)
{
    std::cout << num << std::endl;
}



void Ex1()
{

    int i;
    print_me arr[10];
    
    for (i=0;i < 10; i++)
    {
        arr[i].ptr_val = i;
        arr[i].ptr(arr[i].ptr_val);
    }
}
}



