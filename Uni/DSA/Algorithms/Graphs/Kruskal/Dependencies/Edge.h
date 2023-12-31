#pragma once

struct Edge {
    int index;
    int from;
    int to;
    int weight;

    Edge(int index, int from, int to, int weight) : index(index), from(from), to(to), weight(weight) {}

    bool operator<(const Edge& other) const;

};