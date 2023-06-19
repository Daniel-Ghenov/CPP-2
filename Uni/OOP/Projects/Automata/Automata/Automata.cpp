#include "Automata.h"

Automata::Link::Link(char ch, unsigned dest): ch(ch), dest(dest) {}

Automata::Automata(size_t size): links(size) {}

Automata::Automata(const String& regex){

}
Automata::Automata(char ch){    //automata that recognises the language: {ch}
    if(!belongsToAlphabet(ch))
        throw std::logic_error("letter doesn't belong to language");

}

void Automata::determinate(){
    
    Automata result;
    result.addState();
    result.makeStartState(0);


    Queue<Vector<unsigned>> creationQueue;

    creationQueue.push({startState});

    Vector<Vector<unsigned>> oldToNew;
    oldToNew.push_back({startState});

    while(!creationQueue.empty()){
        Vector<unsigned> currState = creationQueue.peek();

        for(size_t i = 0;;); //add alphabet

    }

    determinate_ = true;
}

bool Automata::isDeterminate() const{
    return determinate_;
}

bool Automata::accepts(const String& word) const{
    Vector<unsigned> reach = reachable(startState, word);
    
    for(size_t i = 0; i < reach.size(); i++){
        if(finalStates.contains(reach[i]))
            return true;
    }
    return false;
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

Vector<unsigned> Automata::reachable(unsigned from, const StringView& str) const{

    Vector<unsigned> reachFrom;
    reachFrom.push_back(from);

    for(size_t i = 0; i < str.size(); i++){
        Vector<unsigned> nextCycle;

        for(size_t j = 0; j < reachFrom.size(); j++){

            for(size_t k = 0; k < links[j].size(); k++){

                if(links[j][k].ch == str[i])
                    nextCycle.push_back(links[j][k].dest);
            }

        }

        if(nextCycle.empty())
            return nextCycle;
        
        reachFrom = std::move(nextCycle);
    }
    return reachFrom;
}

