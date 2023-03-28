#include <iostream>
#include <vector>


class Solution {
public:
    double average(std::vector<int>& salary) {
        std::vector<int> salcontr;
        double ans {0};
        double sum {0};
        int maxnum {salary[0]};
        int minnum {salary[0]};
        for(size_t i {0}; i < salary.size(); i++){
            if(salary[i] > maxnum){
               maxnum = salary[i];
            }
            if(salary[i] < minnum){
                minnum = salary[i];
            }
            
        }
        for(size_t i {0}; i < salary.size(); i++){
            if(salary[i] != maxnum && salary[i] != minnum){salcontr.push_back(salary[i]);}
            
        }
        
        
         for(size_t i {0}; i < salcontr.size(); i++){
             std::cout<<salcontr[i];
             sum += salcontr[i];
         }
        ans = sum / salcontr.size();
        
    return ans;
        
    }
};

int main(){


    std::vector<int> expression{2000, 3000, 4000, 1000};





    return 0;
}