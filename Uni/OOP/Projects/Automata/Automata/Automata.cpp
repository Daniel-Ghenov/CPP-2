#include "Automata.h"

Automata::Automata(size_t states): _stateAmmount(states){}

Automata::Automata(const Automata& other){
    copyFrom(other);
}
Automata::Automata(Automata&& other){
    moveFrom(std::move(other));
}
Automata& Automata::operator=(const Automata& other){
    copyFrom(other);
}
Automata& Automata::operator=(Automata&& other){
    moveFrom(std::move(other));
}

void Automata::determinate(){
    
    Vector<Pair<Vector<int>, int>> newStates({Pair<Vector<int>, int> (_start, 0)});
    Vector<int> newStart = {0};

    for(size_t i {0}; i < newStates; i++);//????




}

bool Automata::isDeterminate() const{
    return _determinate;
}

void Automata::copyFrom(const Automata& other){
    _stateAmmount = other._stateAmmount;
    _links = other._links;
    _start = other._start;
    _final = other._final;

}
void Automata::moveFrom(Automata&& other){
    _stateAmmount = other._stateAmmount;
    _links = std::move(other._links);
    _start = std::move(other._start);
    _final = std::move(other._final);
}