#include "ThroneInheritance.h"

ThroneInheritance::ThroneInheritance(std::string kingName){
    king = new Successor(kingName);

}

void ThroneInheritance::birth(std::string parentName, std::string childName){
    _birth(parentName, childName, king);

}

void ThroneInheritance::death(std::string name){
    if(name == king->name()){
        if(king->size() == 0)
            king = nullptr;
        Successor* newKing = king->children()[0];
        newKing->addChildren(king->children() + 1, king->size() - 1);
        king->kill();
        king = newKing;
        return;
    }
    _death(name, king);

}

std::vector<std::string> ThroneInheritance::getInheritanceOrder(){
    std::vector<std::string> inherList;
    _getInheritanceOrder(king, inherList);
    return inherList;

}
void ThroneInheritance::_birth(std::string parentName, std::string childName, Successor* current){
    if(current->name() == parentName){
        current->addChild(childName);
    }
    for(size_t i {0}; i < current->size(); i++){
        _birth(parentName, childName, current->children()[i]);
    }
}
void ThroneInheritance::_death(std::string name, Successor* current){

    for(size_t i {0}; i < current->size(); i++){
        Successor* iter = current->children()[i];
        if(iter->name() == name){
            current->removeChild(name);
            current->addChildren(iter->children(), iter->size());
            return;
        }
    }

}
    
void ThroneInheritance::_getInheritanceOrder(Successor* current, std::vector<std::string>& currSuccessors){
    currSuccessors.push_back(current->name());
    for(size_t i {0}; i < current->size(); i++){
        _getInheritanceOrder(current->children()[i], currSuccessors);
    }
}
