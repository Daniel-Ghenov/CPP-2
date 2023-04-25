#include <iostream>
#include <vector>

int main ()
{

    std::vector<int> nums = {3, 2, 4};
    int target = 6;
    bool available = false;

    for(size_t i {0}; i < nums.size(); i++){
        for(size_t j {0}; j< nums.size(); j++){
            if(nums[i] + nums[j] == target && i != j){
                std::cout << "[" << i << "," << j << "]";
                available = true;
                break;
            }
        }
        if (available){break;}
    }
    
    if(!available){
        std::cout << "The answer is unavailable with these numbers.";
    }

    
    return 0;
}