#include <iostream>
#include "PriorityQueue.hpp"

int main(){

    PriorityQueue<int> queue;

    queue.push(5, 1);
    queue.push(10, -2);
    queue.push(75, 4);

    std::cout<<queue.peek()<<std::endl; //error in second data after pop possible swap with undefined val
    queue.pop();
    std::cout<<queue.peek()<<std::endl;
    queue.pop();
    std::cout<<queue.peek()<<std::endl;
    queue.pop();

    return 0;
}