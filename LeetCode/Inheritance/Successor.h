#pragma once
#include <string>
#include <vector>
#include "Const.h"

class Successor{
private:
    std::string _name = "\0";
    Successor** _children = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

public:
    Successor() = default;
    Successor(std::string name);
    ~Successor();
    Successor(const Successor& other);
    Successor& operator=(const Successor& other);

    std::string name() const;
    std::string& name();
    Successor** children() const;
    Successor** children();
    size_t size() const;

    Successor* operator[](size_t index);

    void kill();
    void removeChild(std::string name);
    void addChild(std::string name);
    void addChildren(Successor** children, size_t childCount);

private:
    void transferOwner();
    void free();
    void copyFrom(const Successor& other);
    void resize(size_t size);
};