#pragma once
#include <iostream>
#include <fstream>
#include "../../Engine\Helper\String\MyString.h"

enum class Element{
    fire,
    water,
    earth
};
enum class Stance{
    attack,
    deffend
};

class SuperHero{
private:
    String _firstName;
    String _lastName;
    String _heroName;
    size_t _power;
    size_t _cost;
    Element _element;
    Stance _stance;

public:
    SuperHero() = default;
    SuperHero(const String& firstName, const String& lastName, const String& heroName, size_t power,
                size_t cost, Element element, Stance stance);

    const String& firstName() const;
    const String& lastName() const;
    const String& heroName() const;

    size_t power() const;
    size_t cost() const;
    Element element() const;
    Stance stance() const;

    void saveToBinary(std::ofstream& ofs) const;
    void loadFromBinary(std::ifstream& ifs);
    void changeStance();


    void print() const;
    void adminPrint() const;
    
};

std::ostream& operator<<(std::ostream& os, const Element& element);
std::ostream& operator<<(std::ostream& os, const Stance& stance);

std::istream& operator>>(std::istream& is, const Element& element);
std::istream& operator>>(std::istream& is, const Stance& stance);

bool dominates(const Element& element1, const Element& element2);