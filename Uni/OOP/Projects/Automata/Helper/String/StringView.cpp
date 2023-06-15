#include "StringView.h"

StringView::StringView(const String& str): StringView(str.data(), str.size()){}
StringView::StringView(const char* str): StringView(str, strleng(str)){}
StringView::StringView(const char* begin, const char* end): begin(begin), end(end) {}
StringView::StringView(const char* begin, size_t size): begin(begin), end(begin + size) {}

const char& StringView::operator[](size_t pos) const{
    return begin[pos];
}
const char& StringView::at(size_t pos) const{
    if(pos > size())
        throw std::out_of_range("Memory Out Of Range");

    return begin[pos];
}
const char* StringView::data() const{
    return begin;
}
size_t StringView::size() const{
    return end - begin;
}

size_t StringView::length() const{
    return end - begin;
}

StringView StringView::substr(size_t startpos, size_t endpos) const{
    return StringView(begin + startpos, endpos - startpos + 1);
}


