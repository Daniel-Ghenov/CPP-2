#pragma once


template <typename T1, typename T2, typename T3>
struct Tripple{
    T1 first;
    T2 second;
    T3 third;

    Tripple(const T1& first,const T2& second, const T3& third);
    Tripple(T1&& first,T2&& second, T3&& third);

};


template <typename T1, typename T2, typename T3>
Tripple<T1, T2, T3>::Tripple(const T1& first,const T2& second, const T3& third):
                    first(first), second(second), third(third){}

template <typename T1, typename T2, typename T3>
Tripple<T1, T2, T3>::Tripple(T1&& first,T2&& second, T3&& third):
                    first(std::move(first)), second(std::move(second)), third(std::move(third)){}

