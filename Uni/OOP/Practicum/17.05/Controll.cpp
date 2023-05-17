#include "Controll.h"

Controll::Controll(const String& name, size_t size, size_t location): _size(size), _location(location), _name(name){}


void Controll::setSize(size_t size){
    _size = size;
}
size_t Controll::size() const{
    return _size;
}