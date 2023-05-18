#include "PriorityQueue.hpp"

int main(){

    PriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.
  
  q.push('A',0); //adds A with lowest priority: 0
  q.push('B',3);
  q.push('C',2);
  q.push('D',2);
  q.push('E',1);
  
  //q.push('F', 5); //error! No such priority!
  
  std::cout<<q.peek()<<std::endl; // B
  q.pop();
  
  std::cout<<q.peek()<<std::endl; // C
  q.pop();
  
  std::cout<<q.peek()<<std::endl; // D
  q.pop();
  
  std::cout<<q.peek()<<std::endl; // E
  q.pop();
  
  std::cout<<q.peek()<<std::endl; // A
  q.pop();


    return 0;
}