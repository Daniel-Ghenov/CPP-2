#pragma once
#include "String.h"
#include "Vector.hpp"

class Dish{
    String name;
    Vector<String> products;
    size_t price = 0;
    int cookTime = 0;
public:

    Dish() = default;
    Dish(const String& name, const Vector<String>& products, size_t price, int cookTime);
    Dish(String&& name, Vector<String>&& products, size_t price, int cookTime);

};

struct Order{
    String name;
    Vector<String> dishes;

    Order() = default;
    Order(const String& name, const Vector<String>& dishes);
    Order(String&& name, Vector<String>&& dishes);
};

class Restaurant{
private:
    String name;
    Vector<Dish> dishes;

public:
    Restaurant() = default;
    Restaurant(const String& name, const Vector<Dish>& dishes);
    Restaurant(String&& name, Vector<Dish>&& dishes);


    void addDish(const Dish& newDish);
    void getOrder(const Order& order);

    friend class Foodpanda;
};