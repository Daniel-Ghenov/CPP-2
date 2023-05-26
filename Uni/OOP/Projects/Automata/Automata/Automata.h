#pragma once
#include "../Helper\Pair\Pair.hpp"
#include "../Helper\Tripple\Tripple.hpp"
#include "../Helper\Vector\Vector.hpp"


class Automata{
private:

    Vector<Tripple<int, char, int>> _links;
    size_t _stateAmmount = 0;
    bool _determinate = true;
    Vector<int> _start;
    Vector<int> _final;

public:
    Automata() = default;
    Automata(size_t states);
    Automata(const Automata& other);
    Automata(Automata&& other);
    Automata& operator=(const Automata& other);
    Automata& operator=(Automata&& other);

    void determinate();
    bool isDeterminate() const;

private:

    void copyFrom(const Automata& other);
    void moveFrom(Automata&& other);

};