#pragma once

struct Edge {
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    bool operator<(const Edge& other) const;

};