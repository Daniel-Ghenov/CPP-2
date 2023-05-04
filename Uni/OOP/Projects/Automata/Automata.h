#pragma once
#include "State/State.h"

class Automata{
private:
    Vector<State*> begin;
    Vector<State*> ending;
    bool _determinate = true;

public:
    Automata() = default;
    Automata(const Automata& other);
    Automata(Automata&& other);
    Automata& operator=(const Automata& other);
    Automata& operator=(Automata&& other);

    bool determinate() const;

private:

    void free();
    void copyFrom(const Automata& other);
    void move(Automata&& other);

};
