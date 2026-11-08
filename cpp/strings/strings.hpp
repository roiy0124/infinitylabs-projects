#ifndef ILRD_SW181_STRINGS_HPP
#define ILRD_SW181_STRINGS_HPP

#include <cstddef>

static size_t StrLen(const char* str);

int StrCmp(const char* str1, const char* str2);

char* StrCpy(char* dest, const char* src);

char* StrnCpy(char* dest, const char* src, std::size_t count);

int StrnCmp(const char* lhs, const char* rhs, std::size_t count);

int StrCaseCmp(const char* s1, const char* s2);

char* StrChr(char* str, int ch);

char* StrDup(const char* src);

char* StrCat(char* dest, const char* src);

char* StrnCat(char* dest, const char* src, std::size_t count);

char* StrStr(char* haystack, const char* needle);

size_t StrSpn(const char* dest, const char* src);

char* StrTok(char* str, const char* delim);

#endif
