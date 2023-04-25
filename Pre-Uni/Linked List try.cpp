#include <iostream>
#include <cmath>

int main ()
{
    int l1[3] {2,4,3};
    int l2[3] {5,6,4}; 
        double med1 {0};
        double med2 {0};
        
        for (int i {0}; i < (sizeof(l1)/4); i++){
            med1 = med1 + (l1[i] * pow(10, i));
        }
        
        for (int j {0}; j < (sizeof(l2)/4); j++){
            med2 = med2 + (l2[j] * pow(10, j));
        }
            
        double result = med1 + med2;
        
    std::cout << result;
    
    return 0;
}