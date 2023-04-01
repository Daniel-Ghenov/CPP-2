#include <iostream>

int main(){

   int n;
   std::cout<<"Enter a number: ";
   std::cin>>n;

   for(int i {1}; i < n; i++){
    std::cout<<"x = "<<i<<" y = "<<n - i<<std::endl;

   }
}