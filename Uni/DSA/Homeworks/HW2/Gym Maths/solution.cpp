#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

struct WeightLifter{
public:
    int place;
    double diameter;
    double effeciency;

    WeightLifter() = default;
    WeightLifter(double diameter, double time, int place){
        this->diameter = diameter;
        this->place = place;
        this->effeciency = calcEffeciency(diameter, time);
    }

private:
    static double calcEffeciency(double diameter, double time){
        double radius = diameter / 2;
        return ( radius * radius )/ time;
    }
};

bool compare(const WeightLifter& lhs, const WeightLifter& rhs){
    if(lhs.effeciency != rhs.effeciency)
        return lhs.effeciency > rhs.effeciency;
    return lhs.diameter > rhs.diameter;
}

int main() {
    size_t arrSize;
    std::cin>>arrSize;

    std::vector<WeightLifter> arr(arrSize);
    for(int i = 0; i < arrSize; i++){
        double diameter;
        double time;
        std::cin>>diameter>>time;
        arr[i] = WeightLifter(diameter, time, i + 1);
    }
    std::sort(arr.begin(), arr.end(), compare);

    for(auto & i : arr){

        std::cout<<i.place<<' ';
    }
    return 0;
}
