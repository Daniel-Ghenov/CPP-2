#include "Automata\Automata.h"

Automata::Automata(const Automata& other){
    
}
Automata::Automata(Automata&& other){
    
}
Automata& Automata::operator=(const Automata& other){
    
}
Automata& Automata::operator=(Automata&& other){
    
}

bool Automata::determinate() const{
    return _determinate;
}
void Automata::free(){
    for(size_t i {0}; i < _begin.size(); i++){
        delete _begin[i];
    }
}
void Automata::copyFrom(const Automata& other){
    Vector<Vector<State*>> visited;
    _begin.resize(other._begin.size());

    for(size_t i {0}; i < other._begin.size(); i++){
        _begin[i] = new State();
        visited.push_back({_begin[i], other._begin[i]});
        _begin[i]->copy(*other._begin[i], visited);
    }
    
}
void Automata::move(Automata&& other){
    _begin = std::move(other._begin);
    _ending = std::move(other._ending);
    _determinate = other._determinate;
}