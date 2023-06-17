#pragma once
#include "../Helper\Pair\Pair.hpp"
#include "../Helper\Tripple\Tripple.hpp"
#include "../Helper\Vector\Vector.hpp"
#include "../Helper\String\StringView.h"


class Automata{
private:

    struct Link{
        char ch = '\0';
        unsigned dest = -1;
    
        Link() = default;
        Link(char ch, unsigned dest);

    };

    unsigned startState = 0;
    bool determinate_ = true;
    Vector<Vector<Link>> links;
    Vector<unsigned> finalStates;

public:
    Automata() = default;   //empty language automata
    Automata(const String& regex);

    void determinate();
    bool isDeterminate() const;
    void minimize();
    void reverse();

    bool isIn(const String& word) const;

    friend Automata Complement(const Automata& automata);
    friend Automata KleeneStarOf(const Automata& automata);
    friend Automata Union(const Automata& a1, const Automata& a2);
    friend Automata Concatenation(const Automata& a1, const Automata& a2);
private:
    
    Automata(char ch);
    explicit Automata(size_t size);
    void absorb(const Automata& a);

    void makeFinalState(unsigned state);
    unsigned getStart() const;
    size_t getStateCount() const;

    void makeStartState(unsigned state);
    void addState();

    void addLink(unsigned from, char ch, unsigned to);
    void copyLinks(unsigned to, unsigned from);

    bool _isIn(unsigned state, const StringView& word) const;


    Automata reverseLinks();

    bool belongsToAlphabet(char ch) const;
};

Automata Complement(const Automata& automata);
Automata KleeneStarOf(const Automata& automata);
Automata Union(const Automata& a1, const Automata& a2);
Automata Concatenation(const Automata& a1, const Automata& a2);