#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>      // std::atoi
#include "atoi.hpp"

using namespace ilrd;
using namespace std;

void TestStoi()
{
    // Decimal — these work with your current code
    assert(Stoi(10, "0")   == 0);
    assert(Stoi(10, "7")   == 7);
    assert(Stoi(10, "123") == 123);
    assert(Stoi(10, "999") == 999);

    // Binary
    assert(Stoi(2, "1")    == 1);
    assert(Stoi(2, "10")   == 2);
    assert(Stoi(2, "101")  == 5);
    assert(Stoi(2, "1011") == 11);

    // Octal
    assert(Stoi(8, "10")  == 8);
    assert(Stoi(8, "17")  == 15);
    assert(Stoi(8, "123") == 83);

    // Hex — UPPERCASE only (your else-branch assumes 'A'..)
    assert(Stoi(16, "A")   == 10);
    assert(Stoi(16, "F")   == 15);
    assert(Stoi(16, "FF")  == 255);
    assert(Stoi(16, "ABC") == 2748);

    cout << "Stoi tests passed\n";
}

void TestStoi10()
{
    // const char* overload
    assert(Stoi10("0")   == 0);
    assert(Stoi10("42")  == 42);
    assert(Stoi10("123") == 123);

    // NULL guard
    assert(Stoi10(static_cast<const char*>(NULL)) == -1);

    // string overload routes through Stoi(10, ...)
    assert(Stoi10(string("500")) == 500);

    cout << "Stoi10 tests passed\n";
}

// Deliverable 1: compare our atoi to std::atoi
void TestAgainstStdAtoi()
{
    const char* cases[] = { "0", "7", "42", "123", "999", "1000000" };
    for (int i = 0; i < 6; ++i)
        assert(Stoi10(cases[i]) == atoi(cases[i]));

    cout << "Stoi10-vs-atoi tests passed\n";
}

void TestItos()
{
    assert(Itos(0)    == "0");
    assert(Itos(7)    == "7");
    assert(Itos(123)  == "123");
    assert(Itos(999)  == "999");

    // round-trip: Itos then Stoi10 gets back the original
    assert(Stoi10(Itos(45678)) == 45678);

    cout << "Itos tests passed\n";
}

// Capture stdout so we can assert on Print3arrs output
string CapturePrint3arrs(char a1[], int s1, char a2[], int s2, char a3[], int s3)
{
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    Print3arrs(a1, s1, a2, s2, a3, s3);
    cout.rdbuf(old);
    return buffer.str();
}

void TestPrint3arrs()
{
    // Note: Print3arrs ends with endl, so every result has a trailing '\n'

    { char a1[]={'a','b','c'}, a2[]={'b','c','d'}, a3[]={'c'};
      assert(CapturePrint3arrs(a1,3,a2,3,a3,1) == "b \n"); }

    { char a1[]={'a','b','c'}, a2[]={'a','b','d'}, a3[]={'x','y'};
      assert(CapturePrint3arrs(a1,3,a2,3,a3,2) == "a b \n"); }

    { // duplicates print once
      char a1[]={'a','a','a','b'}, a2[]={'a','a','b','b'}, a3[]={'x'};
      assert(CapturePrint3arrs(a1,4,a2,4,a3,1) == "a b \n"); }

    { // all common excluded by arr3
      char a1[]={'a','b','c'}, a2[]={'a','b','c'}, a3[]={'a','b','c'};
      assert(CapturePrint3arrs(a1,3,a2,3,a3,3) == "\n"); }

    { // no intersection
      char a1[]={'a','b'}, a2[]={'c','d'}, a3[]={'x'};
      assert(CapturePrint3arrs(a1,2,a2,2,a3,1) == "\n"); }

    { // output is ASCII-ordered, not arr1-ordered
      char a1[]={'z','a','b'}, a2[]={'z','a','b'}, a3[]={'x'};
      assert(CapturePrint3arrs(a1,3,a2,3,a3,1) == "a b z \n"); }

    cout << "Print3arrs tests passed\n";
}

int main()
{
    TestStoi();
    TestStoi10();
    TestAgainstStdAtoi();
    TestItos();
    TestPrint3arrs();

    cout << "little-endian: " << MyLittleEndian() << "\n";
    cout << "All tests passed\n";
    return 0;
}
