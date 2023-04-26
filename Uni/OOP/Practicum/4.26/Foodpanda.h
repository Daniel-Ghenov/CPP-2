#pragma once
#include "Restaurant.h"

class Foodpanda{
    Vector<Restaurant> restaurants;

public:

    static const size_t nopos = -1;  //return-value for "no instance found"

    Foodpanda() = default;
    Foodpanda(const Vector<Restaurant>& restaurants);
    Foodpanda(Vector<Restaurant>&& restaurants);
    

    void getOrder(const Order& order);

private:
    size_t getRestaurantIdx(const String& name);

};