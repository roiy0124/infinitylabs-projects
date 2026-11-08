#include <cassert>  // assert
#include <cstring>  // strcmp
#include "string.hpp"

using namespace ilrd;

static void TestConstructAndCstr();
static void TestLength();
static void TestCopyCtor();
static void TestAssignment();
static void TestSelfAssignment();
static void TestComparisons();

int main()
{
    TestConstructAndCstr();
    TestLength();
    TestCopyCtor();
    TestAssignment();
    TestSelfAssignment();
    TestComparisons();

    std::cout << "all of the tests passed!" << std::endl;
    return 0;
}

static void TestConstructAndCstr()
{
    String s("hello");
    assert(strcmp(s.Cstr(), "hello") == 0);
}

static void TestLength()
{
    String s("hello");
    assert(s.Length() == 5);

    String empty("");
    assert(empty.Length() == 0);
}

static void TestCopyCtor()
{
    String a("world");
    String b(a);                    
    assert(strcmp(b.Cstr(), "world") == 0);
    assert(a.Cstr() != b.Cstr());   
}

static void TestAssignment()
{
    String a("first");
    String b("second");
    b = a;
    assert(strcmp(b.Cstr(), "first") == 0);
    assert(a.Cstr() != b.Cstr());  
}

static void TestSelfAssignment()
{
    String a("keepme");
    a = a;   
    assert(strcmp(a.Cstr(), "keepme") == 0);
}

static void TestComparisons()
{
    String a("abc");
    String b("abc");
    String c("abd");

    assert(a == b);
    assert(!(a == c));
    assert(a < c);
    assert(c > a);
}
