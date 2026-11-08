#include <iostream>
#include <cassert>
#include <cstring>
#include <cstddef>
#include "pointers2.hpp"

int main()
{
    const char* str1[] = "ete";
    const char* str2[] = "ee";
    const char* str3[] = "etbe";
    if(IsPalindrome(str1) && IsPalindrome(str2) && IsPalindrome(str3))
        std::cout << "Test 1 passed!" << std::endl;
    else
        std::cout << "Test 1 failed!" << std::endl;
    
    if (StrLen(str1) == 3 && StrLen(str2) == 2 && StrLen(str1) == 4)
        std::cout << "Test 2 passed!" << std::endl;
    else
        std::cout << "Test 2 failed!" << std::endl;
    
    char* str4[] = "T     st   3   pas s  ed!"";
    SpaceReview(str4);
    std::cout << str4 << std::endl;
return 0;
}
