#include <iostream>
#include "List.hpp"

int main(){

    List<int> list1;
    list1.push_front(3);
    list1.insert(2, 4);
    list1.remove(2);
    list1.print();

    return 0;
}