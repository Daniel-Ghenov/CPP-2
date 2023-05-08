#pragma once
#include "Link\Link.h"
#include "Vector\Vector.hpp"

class State{
private:
    size_t _refs = 1;
    Vector<Link> _links;

public:
    
    State() = default;
    State(const Vector<Link>& links);
    State(const State& other);
    State(State&& other);
    State& operator=(const State& other) = delete;
    State& operator=(State&& other);
    ~State();

    void addLink(char letter, State* state);
    void addChild(char letter);

    Vector<State*> goTo(char c);

    void copy(const State& other, Vector<Vector<State*>>& visited);
    
private:

    void free();
    void copyFrom(const State& other);

    State(const State& other, Vector<Vector<State*>>& visited);
    void copyFrom(const State& other, Vector<Vector<State*>>& visited);
    void move(State&& other);

    bool contains(const Link& link);
    size_t hasVisited(State* state, Vector<Vector<State*>>& visited) const;
};