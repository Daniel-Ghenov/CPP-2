#include <iostream>
#include <cmath>

int main (){

            int nums [4] {2, 5, 11, 15};
            int target = 9;
            bool available = false;
            
            for (size_t i {0}; i < (sizeof(nums) / 4); i++ ){
                for (size_t j {0}; j < (sizeof(nums) / 4); j++ ){
                    if (nums[i] + nums[j] == target){
                        std::cout << "[" << i << "," << j << "]";
                        available = true;
                        break;
                    }
                }
                if(available){break;}
            }
            
            if (!available){
                std::cout << "Target unavailable with current nums.";
            }
        
    return 0;
}