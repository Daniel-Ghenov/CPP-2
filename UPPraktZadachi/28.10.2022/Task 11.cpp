#include <iostream>

int gcd(int a, int b){

    if(a == 0)
        return b;
    if (b == 0)
        return a;
    if(a == b)
        return a;
    
    if(a > b){
        return(gcd(a-b,b));
    }
    return(gcd(a,b-a));
}
void gcdOfFour(int a,int b,int c ,int d){
    
    std::cout<<gcd(a,b);
    std::cout<<gcd(c,d);
    std::cout<<gcd(gcd(a,b),gcd(c,d));
    
}

int main(){




    return 0;

} 