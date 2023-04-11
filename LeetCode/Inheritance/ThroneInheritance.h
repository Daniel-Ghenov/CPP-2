#pragma once
#include "Successor.h"


class ThroneInheritance {
private:
    Successor* king = nullptr;

public:

    ThroneInheritance(std::string kingName);
    void birth(std::string parentName, std::string childName);
    void death(std::string name);
    std::vector<std::string> getInheritanceOrder();


private:
    void _birth(std::string parentName, std::string childName, Successor* current);
    void _death(std::string name, Successor* current);
    void _getInheritanceOrder(Successor* current, std::vector<std::string>& currSuccessors);

};