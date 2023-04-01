#include <iostream>

int calculate(int a, int b, char action){

    switch(action){
        case '*':
            return a * b;
        case '/':
            return a/b;
        case '%':
            return a % b;
        case '-':
            return a - b;
        default: 
            return a + b;
    }

}

int main(){




    return 0;

} 