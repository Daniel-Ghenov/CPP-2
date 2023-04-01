#include <iostream>

bool isInInterval(int lower, int higher, int check){

    if(check > lower && check < higher)
        return true;
    return false;

}

int askUser(int from, int to){

    int n;
    while(true){
        std::cin>>n;
        if(n >= from && n <= to)
            return n;
    }

}

int main(){




    return 0;

} 