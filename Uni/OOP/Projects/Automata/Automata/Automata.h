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
    Automata(const StringView& str);

    void determinate();
    bool isDeterminate() const;
    void minimize();
    void reverse();

    bool isIn(const StringView& word) const;

    friend Automata Complement(const Automata& automata);
    friend Automata KleeneStarOf(const Automata& automata);
    friend Automata Union(const Automata& a1, const Automata& a2);
    friend Automata Concatenation(const Automata& a1, const Automata& a2);
private:

    Automata(char ch);

    void makeFinalState(unsigned state);
    bool getStart() const;

    void makeStartState(unsigned state);
    void addState();
    void absorb(const Automata& other);

    bool belongsToAlphabet(char ch) const;
    void addLink(unsigned from, char ch, unsigned to);
    void copyLinks(unsigned from, unsigned to);

    bool _isIn(unsigned state, const StringView& word) const;
};

Automata Complement(const Automata& automata);
Automata KleeneStarOf(const Automata& automata);
Automata Union(const Automata& a1, const Automata& a2);
Automata Concatenation(const Automata& a1, const Automata& a2);