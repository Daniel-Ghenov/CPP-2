#include "Base\BaseIF.h"

BaseIF::BaseIF(System* ptr): _sys(ptr){
    
}
BaseIF::BaseIF(BaseIF&& other){
    _sys = other._sys;
    other._sys = nullptr;
}

System* BaseIF::sys(){
    return _sys;
}

