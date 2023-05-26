#pragma once

template<typename T1, typename T2>
struct Pair{
    T1 first;
    T2 second;

    Pair(const T1& first, const T2& second);
    Pair(T1&& first, T2&& second);


};


template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first, const T2& second): first(first), second(second){}
template<typename T1, typename T2>
Pair<T1, T2>::Pair(T1&& first, T2&& second): first(std::move(first)), second(std::move(second)){}