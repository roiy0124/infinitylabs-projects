#include <iostream>
#include <cassert>
#include <cstring>
#include <cstddef>
#include "strings.hpp"

int main()
{
    // test 1 
    char* dest = new char[15];
    const char src[] = "test 1 passed!";
    dest = StrCpy(dest, src);
    std::cout << dest << std::endl;
    // test 2
    char* dest2 = new char[15];
    const char src2[] = "test 2 passed!";
    dest2 = StrnCpy(dest2, src2,15);
    std::cout << dest2 << std::endl;
    // test 3
    const char lhs3[] = "Apple";
    const char src3[] = "BApple";
    if(StrnCmp(lhs3, src3, 15) < 0)
        std::cout << "test 3 passed!"<< std::endl;
    else
        std::cout << "test 3 failed!"<< std::endl;
    // test 4
    const char lhs4[] = "Apple";
    const char src4[] = "BApple";
    if(StrCaseCmp(lhs4, src4))
        std::cout << "test 4 passed!"<< std::endl;
    else
        std::cout << "test 4 failed!"<< std::endl;
    // test 5
    char str5[] = "Apple";
    if(*(StrChr(str5, 65)) == 'A' && StrChr(str5, 70) == nullptr)
        std::cout << "test 5 passed!"<< std::endl;
    // test 6
    const char src6[] = "test 6 passed!";
    char* dest6 = StrDup(src6);
    std::cout << dest6 << std::endl;
    
    // test 7
    
    return 0;
}
