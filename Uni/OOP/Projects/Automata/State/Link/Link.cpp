#include "Link\Link.h"

Link::Link(char letter, State* ptr): _letter(letter), _ptr(ptr){}

bool Link::operator==(const Link& other) const{
    return(_letter == other._letter) && (_ptr == other._ptr);
}
