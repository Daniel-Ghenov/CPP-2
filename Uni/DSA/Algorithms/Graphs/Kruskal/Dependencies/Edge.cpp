#include "Edge.h"

bool Edge::operator<(const Edge& other) const{
    if(weight == other.weight) {
        if(from == other.from) {
            return to < other.to;
        }
        return from < other.from;
    }
return weight < other.weight;
}