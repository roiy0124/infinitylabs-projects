// WS: Simple String
// Name: Roie Itzhakov
// Reviewer: Sagi Dahari
// Date: 20/08/2026

#include <cstddef>   // size_t
#include <iostream>  // cout  
#include <cstring>   // strcpy
#include <cassert>   // assert

#include "string.hpp"

namespace ilrd
{

String::String(const char* str) : m_cstr(new (std::nothrow) char[std::strlen(str) + 1])
{
    assert(NULL != m_cstr);
    std::strcpy(m_cstr, str);
}

String::String(const String& other) : m_cstr(new (std::nothrow) char[std::strlen(other.m_cstr) + 1])
{
    assert(NULL != m_cstr);
    std::strcpy(m_cstr, other.m_cstr);
}

String::~String()
{
    delete[] m_cstr;
}

String& String::operator=(const String& o)
{
    char* tmp = new (std::nothrow) char[std::strlen(o.m_cstr) + 1];
    if(NULL == tmp)
    {
        return *this;
    }
    
    std::strcpy(tmp, o.m_cstr);
    delete[] m_cstr;
    m_cstr = tmp;

    return *this;
}

size_t String::Length() const
{
    return std::strlen(m_cstr);
}
    
const char* String::Cstr() const
{   
    return m_cstr;
}
    
void Foo(String& s)
{
    std::cout << s.Cstr() << std::endl;
}
    
String Bla()
{
    return "efg";
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.Cstr();
    return os;
}
    
bool operator==(const String& str1, const String& str2)
{
    return std::strcmp(str1.Cstr(), str2.Cstr()) == 0;
}
    
bool operator>(const String& a, const String& b)
{ 
    return std::strcmp(a.Cstr(), b.Cstr()) > 0;
}
    
bool operator<(const String& a, const String& b)
{ 
    return std::strcmp(a.Cstr(), b.Cstr()) < 0;
}
}    


