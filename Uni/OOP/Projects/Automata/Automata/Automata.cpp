#include "Automata.h"

Automata::Link::Link(char ch, unsigned state): ch(ch), state(state) {}

Automata::Automata(size_t size): links(size) {}

Automata::Automata(const String& regex){

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



bool Automata::isIn(const String& word) const{
    
}

void Automata::reverse(){

    Automata reversedLinks = reverseLinks();
    reversedLinks.makeFinalState(startState);

    reversedLinks.addState(); // adding new start State
    reversedLinks.makeStartState(links.size() - 1);

    for(size_t i = 0; i < finalStates.size(); i++){
        reversedLinks.copyLinks(reversedLinks.startState, finalStates[i]);
    }

    if(finalStates.contains(startState))    //the new start state is final if the old start was final
        reversedLinks.makeFinalState(reversedLinks.startState);
    
    *this = reversedLinks;
}


Automata Complement(const Automata& automata){
    Automata result = automata;

    Vector<unsigned> newFinal;
    for(size_t i = 0; i < automata.links.size(); i++){
        if(!automata.finalStates.contains(i))
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
        result.copyLinks(result.finalStates[i], result.startState);
    }

}
Automata Union(const Automata& a1, const Automata& a2){
    
    Automata result = a1;
    result.absorb(a2);
    result.addState();
    result.makeStartState(result.links.size() - 1);
    result.copyLinks(result.startState , a1.startState);
    result.copyLinks(result.startState, a1.getStateCount() + a2.startState - 1);

    if(a1.finalStates.contains(a1.startState) || a2.finalStates.contains(a2.startState))
        result.makeFinalState(result.startState);

    return result;

}
Automata Concatenation(const Automata& a1, const Automata& a2){

    Automata result = a1;
    result.absorb(a2);

    for(size_t i = 0; i < a1.finalStates.size(); i++){
        result.copyLinks(a1.finalStates[i], a2.startState + a1.getStateCount());
    }

    if(!a2.finalStates.contains(a2.startState))
        result.finalStates.clear();

    for(size_t i = 0; i < a2.finalStates.size(); i++){
        result.makeFinalState(a2.finalStates[i] + a1.getStateCount());
    }
    return result;
}

 
void Automata::absorb(const Automata& a){
    size_t currSize = links.size();

    for(size_t i = 0; i < a.links.size(); i++){
        links.push_back(a.links[i]);

        for(size_t j = 0; j < a.links[i].size(); j++){
            links[i][j].dest += currSize;
        }

        if(a.finalStates.contains(i))
            finalStates.push_back(i + currSize);
    }
    
}

void Automata::makeFinalState(unsigned state){
    if(finalStates.contains(state))
        finalStates.push_back(state);
}


void Automata::makeStartState(unsigned state){
    startState = state;
}
unsigned Automata::getStart() const{
    return startState;
}
size_t Automata::getStateCount() const{
    return links.size();
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

void Automata::copyLinks( unsigned to, unsigned from){

    for(size_t i = 0; i < links[from].size(); i++){
        links[to].push_back(links[from][i]);
    }
}


Automata Automata::reverseLinks(){

    Automata result(links.size());

    for(size_t i = 0; i < links.size(); i++){

        for(size_t j = 0; j < links[i].size(); j++){
            result.addLink(links[i][j].dest, links[i][j].ch, i);
        }

    }

    return result;
}

bool Automata::belongsToAlphabet(char ch) const{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '1');
}





bool Automata::_isIn(unsigned state, const StringView& word) const{
    if(word.size() == 0)
        return finalStates.contains(state);
    
    for(size_t i {0}; i < links[state].size(); i++){

        if(word[0] == links[state][i].ch && _isIn(links[state][i].dest , word.substr(1, word.size())))
            return true;
    }
    return false;
}
