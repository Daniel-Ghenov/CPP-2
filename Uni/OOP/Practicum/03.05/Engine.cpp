#include "Engine.h"    

Engine::Engine(const String& manufacturer, const String& descrpition, size_t HP): CarPart(manufacturer, descrpition){
    setHP(HP);
}


void Engine::setHP(size_t HP){
    this->HP = HP;

}

size_t Engine::getHP() const{
    return this->HP;

}

std::ostream& operator<<(std::ostream& os, const Engine& engine){
    return os<<(CarPart&)engine<<engine.getHP()<<" hp";
}
