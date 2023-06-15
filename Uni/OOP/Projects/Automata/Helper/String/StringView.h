#pragma once
#include "MyString.h"

class StringView{
private:
    const char* begin = nullptr;
    const char* end = nullptr;

public:

    StringView() = default;
    StringView(const String& str);
    StringView(const char* str);
    StringView(const char* begin, const char* end);
    StringView(const char* begin, size_t size);


    const char& operator[](size_t pos) const;
    const char& at(size_t pos) const;

    const char* data() const;


    size_t size() const;    //Capacity
    size_t length() const;
    StringView substr(size_t startpos, size_t endpos) const;  //String Operations



};