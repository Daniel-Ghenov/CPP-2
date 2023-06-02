#pragma once
#include <cassert>
#include <limits>
#include "Pair.hpp"
#include "Vector.hpp"

template <typename T>
class PriorityQueue{
private:
    Vector<Pair<T, int>> data;

public:

    void push(const T& data, int priority);
    void pop();
    const T& peek() const;
    bool empty() const;

private:
    void maxHeapify(size_t pos);
    void changePrioirity(size_t pos, int newPriority);
};


template <typename T>
void PriorityQueue<T>::push(const T& t_data, int priority){
    data.push_back(Pair<T, int>(t_data, std::numeric_limits<int>::min()));
    changePrioirity(data.size() - 1, priority);
}


template <typename T>
const T& PriorityQueue<T>::peek() const{
    return data[0].first;
}
    
template <typename T>
void PriorityQueue<T>::pop(){

    std::swap(data[0], data[data.size() - 1]);
    data.pop_back();
    maxHeapify(0);
}

template <typename T>
bool PriorityQueue<T>::empty() const{
    return data;
}


template <typename T>
void PriorityQueue<T>::maxHeapify(size_t pos){
    
    size_t left = pos * 2 + 1;
    size_t right = left + 1;
    size_t max = pos;

    if(left < data.size() && data[pos].second < data[left].second)
        max = left;
    if(right < data.size() && data[max].second < data[right].second)
        max = right;

    if(max != pos){
        std::swap(data[pos], data[max]);
        maxHeapify(max);
    }

}

template <typename T>
void PriorityQueue<T>::changePrioirity(size_t pos, int newPriority){

    assert(newPriority > data[pos].second);

    data[pos].second = newPriority;
    size_t parent = pos / 2;

    while(data[parent].second < data[pos].second){
        std::swap(data[parent], data[pos]);
        pos = parent;
        parent = pos / 2;
    }

}

