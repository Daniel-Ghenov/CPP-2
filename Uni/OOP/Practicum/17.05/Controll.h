#pragma once
#include "MyString.h"


class Controll{
    String _name;
    size_t _size;
    size_t _location;

public:
    Controll() = default;
    Controll(const String& name, size_t size, size_t location);

    void setSize(size_t size);
    size_t size() const;

    virtual void setDataDialog() = 0;
    virtual ~Controll() = default;
};
