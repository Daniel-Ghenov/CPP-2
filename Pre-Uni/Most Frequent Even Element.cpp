#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    bool checknums (std::vector<int>& nums, int startpos, int& ammount, int cnum){

        bool check = false;
        if(startpos > nums.size() - 1){return check;}
        
        std::cout<<"Starting inner loop at pos: "<<startpos<<" and value: "<<nums[startpos]<<std::endl;
        int i = startpos;
        std::vector<int>::iterator it;
        
            if( cnum % 2 == 0){
                it = std::find(nums.begin() + i, nums.end(),cnum);
                if(it != nums.end()){
                    ammount++;
                    int distance = std::distance(nums.begin(), it);
                    std::cout<<*it << " found at: "<<distance<<std::endl;
                    checknums(nums, distance+ 1, ammount, cnum);
                    check = true;
                }      
            }
             
    return check;
    }
    int mostFrequentEven(std::vector<int>& nums) {
        std::cout<<"_____________________"<<std::endl;
        std::cout<<"Program running"<<std::endl;
        int answer {0};
        int ammount {0};
        
        for(auto i : nums){
            std::cout<<"Starting loop number: "<< i<<std::endl;
                checknums(nums, i, ammount,nums[i]);
                if(ammount > answer){
                    answer = ammount;
                    std::cout<<"Appending to answer at: "<<i<<std::endl;
                }
            ammount = 0;
            
        }
        if(answer == 0){answer = -1;}
        return answer;
    }
};

int main(){

    std::vector<int> nums {0,1,2,3,1,1,5};
    Solution m;
    m.mostFrequentEven(nums);


return 0;
}