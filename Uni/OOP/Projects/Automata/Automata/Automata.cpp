#include "Automata.h"

Automata::Link::Link(char ch, unsigned dest): ch(ch), dest(dest) {}

Automata::Automata(const StringView& str){

}
Automata::Automata(char ch){    //automata that recognises the language: {ch}
    if(!belongsToAlphabet(ch))
        throw std::logic_error("letter doesn't belong to language");

}

void Automata::determinate(){
    
}

bool Automata::isDeterminate() const{
    return determinate_;
}





bool Automata::isIn(const StringView& word) const{
    
}

Automata Complement(const Automata& automata){
    Automata result = automata;

    Vector<unsigned> newFinal;
    for(size_t i = 0; i < automata.links.size(); i++){
        if(!automata.finalStates.contains(i))
            newFinal.push_back(i);
    }

    result.finalStates = std::move(newFinal);

    return result;
}
Automata KleeneStarOf(const Automata& automata){
    Automata result = automata;

    result.makeFinalState(result.startState);

    for(size_t i = 0; i < result.finalStates.size(); i++){
        result.copyLinks(result.startState, result.finalStates[i]);
    }

}
Automata Union(const Automata& a1, const Automata& a2){
    
    Automata result = a1;
    result.addState();
    result.makeStartState(result.links.size() - 1);
    result.copyLinks(a1.startState, result.startState);
    

}
Automata Concatenation(const Automata& a1, const Automata& a2){

    Automata result = a1;
    result.absorb(a2);

}
 

void Automata::makeFinalState(unsigned state){
    if(finalStates.contains(state))
        finalStates.push_back(state);
}


void Automata::makeStartState(unsigned state){
    startState = state;
}
bool Automata::getStart() const{
    return startState;
}

void Automata::addState(){
    links.push_back(Vector<Link>());
}
void Automata::absorb(const Automata& other){

    size_t currSize = links.size();

    for(size_t i = 0; i < other.links.size(); i++){
        links.push_back(other.links[i]);

        for(size_t j = 0 ; j < other.links[i].size(); j++){
            links[currSize + i][j].dest += currSize;

        }
    }

    for(size_t i {0}; i < other.finalStates.size(); i++){
        finalStates.push_back(other.finalStates[i] + currSize);
    }

}

void Automata::addLink(unsigned from, char ch, unsigned to){
    links[from].push_back({ch, to});
}

void Automata::copyLinks(unsigned from, unsigned to){

    for(size_t i = 0; i < links[from].size(); i++){
        links[to].push_back(links[from][i]);
    }
}


bool Automata::belongsToAlphabet(char ch) const{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '1');
}


