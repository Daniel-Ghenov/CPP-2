#pragma once
#include <iostream>
#include "MyString.h"

class insufficient_fuel_error: public std::logic_error{
public:
    insufficient_fuel_error() = default;
    insufficient_fuel_error(const char* str): logic_error(str){}

};