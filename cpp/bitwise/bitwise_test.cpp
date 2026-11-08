#include <iostream>
#include <cassert>
#include "bitwise.hpp"

using namespace std;
using namespace ilrd;

int main()
{
    assert(Pow2(2,3) == 16);
    assert(Pow2(3,5) == 96);
    assert(Pow2(5,0) == 5);
    
    cout << "Pow Passed" << endl;
    
    assert(IsPow2Loop(8) != 0);
    assert(IsPow2Loop(9) == 0);
    assert(IsPow2Loop(32) == 1);
    cout << "IsPow2Loop Passed" << endl;
    
    assert(IsPow2(8) != 0);
    assert(IsPow2(9) == 0);
    assert(IsPow2(32) == 1);
    cout << "IsPow2 Passed" << endl;
    
    assert(Increment(32) == 33);
    assert(Increment(5432) == 5433);
    cout << "Increment Passed" << endl;
    
     
    unsigned int arr[] = {25,456,1,7,6};
    PrintSet3(arr, 5);
    cout << "PrintSet3 Passed" << endl;
    
    unsigned int x = 1;
    
    assert(ByteMirrorLoop(x) == x << 31);
    cout << "ByteMirrorLoop Passed" << endl;
    
    assert(Check2And6(34) == 1);
    assert(Check2And6(3) ==0);
    cout << "Check2And6 Passed" << endl;
    
    

}
