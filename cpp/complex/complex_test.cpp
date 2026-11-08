#include <cassert> // assert

#include "complex.hpp"

using namespace ilrd;

static void TestGetSet();

int main()
{
    TestGetSet();
    std::cout << "all of  the tests passed!" << std::endl;
    return 0;
}

static void TestGetSet()
{
    Complex c;
    c.SetReal(3.14);
    assert(c.GetReal() == 3.14);
    
    c.SetImg(6.1);
    assert(c.GetImg() == 6.1);
}


