#include "Automata.h"

Automata::Link::Link(char ch, unsigned state): ch(ch), state(state) {}

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
        if(!automata.isFinal(i))
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

}
 

void Automata::makeFinalState(unsigned state){
    if(finalStates.contains(state))
        finalStates.push_back(state);
}
bool Automata::isFinal(unsigned state) const{
    if(finalStates.contains(state))
        return true;
    return false;

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




bool Automata::_isIn(unsigned state, const StringView& word) const{
    if(word.size() == 0)
        return isFinal(state);
    
    for(size_t i {0}; i < links[state].size(); i++){

        if(word[0] == links[state][i].ch && _isIn(links[state][i].state , word.substr(1, word.size())))
            return true;
    }
    return false;
}
