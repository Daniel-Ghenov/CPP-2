#include <iostream>
#include "ThroneInheritance.h"

int main(){
    ThroneInheritance obj1("King");
    obj1.birth("King", "Anna");
    obj1.birth("Anna", "Bob");
    obj1.birth("King", "John");
    obj1.death("Anna");

    std::vector<std::string> order = obj1.getInheritanceOrder();
    for(size_t i {0}; i < order.size(); i++){
        std::cout<<order[i];
    }

}