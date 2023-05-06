#pragma once
#include "Iterator\ReverseIter.hpp"

template<class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& find){    //returns iterator to first instance of find

    while (first < last){
       if(*first == find){
            return Iterator(first);
       }
       first++;
    }
    return last;
}


template<class Iterator, class BoolFunc>
Iterator findIf(Iterator first, Iterator last, BoolFunc condition){    //returns iterator to first instance to meet condition

    while(first < last){
        if(condition(*first)){
            return *first;
        }
    }
    return last;
}


template<class Iterator, class boolFunc>
Iterator findIfNot(Iterator first, Iterator last, boolFunc condition){

    while(first < last){
        if(!condition(*first)){
            return *first;
        }
    }
    return last;
}

template<class Iterator, class T>
int count(Iterator first, Iterator last, const T& find){ //returns the count of find

    int count = 0;
    while (first < last){
       if(*first == find){
            count++;
       }
       first++;
    }
    return count;
}

template<class Iterator, class BoolFunc>
int countIf(Iterator first, Iterator last, BoolFunc condition){    //returns the count that matches condition

    int count = 0;
    while(first < last){
        if(condition(*first)){
            count++;
        }
    }
    return count;
}

template<class Iterator, class UnaryFunc>
void forEach(Iterator first, Iterator last, UnaryFunc f){

    while(first < last){
        f(*first);
    }
}