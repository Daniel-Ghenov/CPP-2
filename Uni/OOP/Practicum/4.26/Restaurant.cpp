#include "Restaurant.h"


Dish::Dish(const String& name, const Vector<String>& products, size_t price, int cookTime):
            name(name), products(products), price(price), cookTime(cookTime){
    

}
Dish::Dish(String&& name, Vector<String>&& products, size_t price, int cookTime):
            name(std::move(name)), products(std::move(products)), price(price), cookTime(cookTime){

}


Order::Order(const String& name, const Vector<String>& dishes):
            name(name), dishes(dishes){
    

}
Order::Order(String&& name, Vector<String>&& dishes):
            name(std::move(name)), dishes(std::move(dishes)){
    

}

Restaurant::Restaurant(const String& name, const Vector<Dish>& dishes):
            name(name), dishes(dishes){
    
}
Restaurant::Restaurant(String&& name, Vector<Dish>&& dishes):
            name(std::move(name)), dishes(std::move(dishes)){
    
}

void Restaurant::addDish(const Dish& newDish){
    dishes.push_back(newDish);
}
void Restaurant::getOrder(const Order& order){
    assert(order.name == this->name);

    for(size_t i {0}; i < order.dishes.size(); i++){
        size_t dishIdx = std::
    }

    
}