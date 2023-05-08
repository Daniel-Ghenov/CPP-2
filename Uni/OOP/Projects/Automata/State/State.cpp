#include "State\State.h"

void State::addLink(char letter, State* state){
    if(contains({letter, state}))
        return;

    _links.push_back({letter, state});
    state->_refs++;
}
void State::addChild(char letter){
    _links.push_back({letter, new State()});
}

State::State(const Vector<Link>& links): _links(links){ }

State::State(const State& other){
    copyFrom(other);
}
State::State(State&& other){
    move(std::move(other));
}

State& State::operator=(State&& other){
    if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

State& State::operator=(const State& other){

}


State::~State(){
    free();
}


Vector<State*> State::goTo(char c){
    Vector<State*> children(_links.size()/2);

    for(size_t i {0}; i < _links.size(); i++){
        if(_links[i]._letter == c){
            children.push_back(_links[i]._ptr);
        }
    }
    return children;
}




bool State::contains(const Link& link){
    for(size_t i {0}; i < _links.size(); i++){
        if(_links[i] == link)
            return true;
    }
    return false;
}

void State::copy(const State& other, Vector<Vector<State*>>& visited){
    if(this != &other){
        free();
        copyFrom(other, visited);
    }
}



void State::free(){
    for(size_t i {0}; i < _links.size(); i++){
        if(_links[i]._ptr->_refs == 1){
            delete _links[i]._ptr;
        }
        else
            _links[i]._ptr->_refs--;
    }
    _links.clear();
}

void State::copyFrom(const State& other){
    Vector<Vector<State*>> visited;
    copyFrom(other, visited);//starting the recurrsion
}

State::State(const State& other, Vector<Vector<State*>>& visited){
    copyFrom(other, visited);
}

void State::copyFrom(const State& other, Vector<Vector<State*>>& visited){  //holding a vector of visited pairs so we don't get into a infinite loop
                                                                            //if we see a pair we have already associated we redirect new links to the same inserted State
    for(size_t i {0}; i < other._links.size(); i++){

        size_t index = hasVisited(other._links[i]._ptr, visited);   //we check if we have already seen this state
        if(index != (size_t)-1){    
            _links.push_back({other._links[i]._letter, visited[index][1]}); //if we have we just redirect our new link to the State we have created
            visited[index][1]->_refs++;
        }
        else{
            size_t currentLink = visited.size();    //the new Link we are going to create will be inside on the position of the current size
            visited.push_back(Vector<State*> (2, other._links[i]._ptr));  //if we have not we write this new pair down and continue
            visited[currentLink][1] = new State(*(other._links[i]._ptr), visited);   //the second element inside the new pair of visited
            _links.push_back({other._links[i]._letter, visited[currentLink][1]});
        }

    }
}
void State::move(State&& other){
    for(size_t i {0}; i < other._links.size(); i++){
        _links.push_back(other._links[i]);
    }
    other._links.clear();
}

size_t State::hasVisited( State* state, Vector<Vector<State*>>& visited) const{
    for(size_t i {0}; i < visited.size(); i++){
        if(visited[i][0] == state)
            return i;
    }
    return -1;
}
