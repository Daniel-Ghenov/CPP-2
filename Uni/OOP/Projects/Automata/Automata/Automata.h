#pragma once
#include "../Helper\Pair\Pair.hpp"
#include "../Helper\Tripple\Tripple.hpp"
#include "../Helper\Vector\Vector.hpp"
#include "../Helper\String\StringView.h"


class Automata{
private:

    unsigned stateAmmount = 0;
    bool determinate_ = true;
    Vector<Tripple<unsigned, char, unsigned>> links;
    Vector<unsigned> startStates;
    Vector<unsigned> finalStates;

public:
    Automata() = default;
    Automata(const StringView& str);

    void determinate();
    bool isDeterminate() const;
    void uniteWith(const Automata& other);
    void concatWith(const Automata& other);
    void star();

    bool isIn(const StringView& word) const;


private:

    Automata(char ch);

    void addStartStates(const Automata& other);
    void addFinalStates(const Automata& other);
    void addLinks(const Automata& other);

    bool isFinal(unsigned state) const;
    bool isStarting(unsigned state) const;

    bool belongsToAlphabet(char ch) const;

    bool _isIn(unsigned state, const StringView& word) const;
};