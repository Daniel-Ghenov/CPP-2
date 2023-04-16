#include "String Creator.h"

int main(){

    StringCreator sc(2);

    sc.addPiece("test");
    sc.addPiece();
    sc.addPiece("football");

    sc[1] << " friends ";
    " Hello " >> sc[1];
    10 >> sc[2];

    String result1 = sc.getString(); // "test Hello friends 10football"
    std::cout<<result1<<std::endl;

    sc.swap(1,2);
    String result2 = sc.getString(); // "test10football Hello friends"
    std::cout<<result2<<std::endl;

    sc.remove(1);
    String result3 = sc.getString(); // "test10                     Hello friends"
    std::cout<<result3<<std::endl;



    return 0;
}