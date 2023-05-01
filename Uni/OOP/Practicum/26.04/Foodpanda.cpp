#include "Foodpanda.h"

Foodpanda::Foodpanda(const Vector<Restaurant>& restaurants):
                    restaurants(restaurants){
    

}
Foodpanda::Foodpanda(Vector<Restaurant>&& restaurants):
            restaurants(std::move(restaurants)){
    
}
void Foodpanda::getOrder(const Order& order){
    try{
        restaurants[getRestaurantIdx(order.name)].getOrder(order);

    }catch(const std::logic_error& err){
        std::cout<<err.what();
    }

}
size_t Foodpanda::getRestaurantIdx(const String& name){

    for(size_t i {0}; i < restaurants.size(); i++){
        if(restaurants[i].name == name){
            return i;
        }
    }
    
    throw std::logic_error("Restaurant Not Found");
}
