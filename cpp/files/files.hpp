#ifndef ILRD_SW181_FILES_HPP
#define ILRD_SW181_FILES_HPP

namespace ilrd
{

enum Status
{
    SUCCESS,
    ALLOCATION_FAILED,
    FILE_RENAME_FAILED,
    FILE_WRITE_FAILED,
    FILE_DELETE_FAILED,
    FILE_READ_FAILED
};

struct FuncHandler
{
    const char* str;
    Status (*operation)(const char* path, const char* line);
    int  (*compare)(const char* str1, const char* str2);
};

typedef void (*FuncPtr)(int);
struct print_me
    {
        int ptr_val;
        FuncPtr ptr = Print;
    };

void FileLogger(const char* path);
void Logger(const char* path);
void Ex1();
}

#endif
