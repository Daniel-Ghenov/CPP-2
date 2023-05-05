#pragma once

template <typename T1, typename T2>
class Pair{
private:
    T1 _first;
    T2 _second;
public:
    const T1& first() const;
    const T2& second() const;
    T1& first();
    T2& second();
};

template <typename T1, typename T2>
const T1& Pair<T1,T2>::first() const{
    return _first;
}
template <typename T1, typename T2>
const T2& Pair<T1,T2>::second() const{
    return _second;
}
template <typename T1, typename T2>
T1& Pair<T1,T2>::first(){
    return _first;
}
template <typename T1, typename T2>
T2& Pair<T1,T2>::second(){
    return _second;
}