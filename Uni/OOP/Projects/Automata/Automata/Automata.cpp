#include "Automata.h"

Automata::Automata(const StringView& str){

}
Automata::Automata(char ch){    //automata that recognises the language: {ch}
    if(!belongsToAlphabet(ch))
        throw std::logic_error("letter doesn't belong to language");

    stateAmmount = 2;
    startStates.push_back(0);
    finalStates.push_back(1);
    links.push_back({0, ch, 1});
    determinate_ = true;
}

void Automata::determinate(){
    
    Vector<Pair<Vector<unsigned>, unsigned>> newStates({Pair<Vector<unsigned>, unsigned> (startStates, 0)});
    Vector<unsigned> newstartStates = {0};

    for(size_t i {0}; i < newStates; i++);//????




}

bool Automata::isDeterminate() const{
    return determinate;
}



void Automata::uniteWith(const Automata& other){

    addStartStates(other);
    addFinalStates(other);
    addLinks(other);

    for(size_t i {0}; i < other.links.size(); i++)
        links.push_back({other.links[i].first + stateAmmount, other.links[i].second, other.links[i].third + stateAmmount});

    determinate_ = false;

    stateAmmount += other.stateAmmount;
}

void Automata::concatWith(const Automata& other){

    if(isIn("")){   //check if epsilon is in the language
        addStartStates(other);
    }

    finalStates.clear();
    addFinalStates(other);
    addLinks(other);
    for(size_t i {0}; i < links.size(); i++){

        if(isFinal(links[i].third)){
            links[i].third = other.startStates[0] + stateAmmount;   //move into other function??

            for(size_t j {1}; j < other.startStates.size(); j++){
                links.push_back({links[i].first, links[i].second, other.startStates[j] + stateAmmount});
            }
        }
        
    }
}

void Automata::star(){
    for(size_t i {0}; i < links.size(); i++){

        if(isFinal(links[i].third)){
            links[i].third = startStates[0];   //move into other function??

            for(size_t j {1}; j < startStates.size(); j++){
                links.push_back({links[i].first, links[i].second, startStates[j]});
            }
        }
    }

    finalStates.clear();
    for(size_t i {0}; i < startStates.size(); i++){
        if(!isFinal(startStates[i]))
            finalStates.push_back(startStates[i]);
    }

}


bool Automata::isIn(const StringView& word) const{
    for(size_t i {0}; i < startStates.size(); i++){
        if(_isIn(startStates[i], word))
            return true;
    }
    return false;
}


void Automata::addStartStates(const Automata& other){
    for(size_t i {0}; i < other.startStates.size(); i++)
        startStates.push_back(other.startStates[i] + stateAmmount);
}

void Automata::addFinalStates(const Automata& other){
    for(size_t i {0}; i < other.finalStates.size(); i++)
        finalStates.push_back(other.finalStates[i] + stateAmmount);
}
void Automata::addLinks(const Automata& other){
    for(size_t i {0}; i < other.links.size(); i++)
        links.push_back({other.links[i].first + stateAmmount, other.links[i].second, other.links[i].third + stateAmmount});
}
 

bool Automata::isFinal(unsigned state) const{
    if(finalStates.contains(state))
        return true;
    return false;

}
bool Automata::isStarting(unsigned state) const{
    if(startStates.contains(state))
        return true;
    return false;
}

bool Automata::belongsToAlphabet(char ch) const{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '1');
}




bool Automata::_isIn(unsigned state, const StringView& word) const{
    if(word.size() == 0)
        return isFinal(state);
    
    for(size_t i {0}; i < links.size(); i++){
        if(links[i].first == state && word[0] == links[i].second && _isIn(links[i].third, word.substr(1, word.size())))
            return true;
    }
    return false;
}
