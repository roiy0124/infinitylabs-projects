#ifndef ILRD_SW181_STRING_HPP
#define ILRD_SW181_STRING_HPP

#include <cstddef>
#include <iostream>

namespace ilrd {

class String
{
    public:
    size_t Length() const;
    const char * Cstr() const;
    
    String(const char* str = "");
    String(const String& other);
    String& operator=(const String& o);
    ~String();
    
    private:
    char* m_cstr;
};

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);
bool operator==(const String& str1, const String& str2);
bool operator>(const String& str1, const String& str2);
bool operator<(const String& str1, const String& str2);
}

#endif


