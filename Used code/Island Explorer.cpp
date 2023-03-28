#include <iostream>
#include <vector>
#include <algorithm>



int numIslands(std::vector<std::vector<char>>& grid) {
    int ans {0};
    int ctrl {0};
    std::vector<std::vector<size_t>> gridcheck;
    
    for(size_t i {0}; i < grid.size(); i++){
        for(size_t j {0}; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                ctrl = gridcheck.size();
                for(size_t n {0}; n < gridcheck.size(); n++){
                    if(gridcheck[n][0] == i && gridcheck[n][1] == j){ctrl--;}
                    else if(gridcheck[n][0] == i + 1 && gridcheck[n][1] == j ){ctrl--;}
                    else if(gridcheck[n][0] == i  && gridcheck[n][1] == j + 1){ctrl--;}}
                if(ctrl == gridcheck.size()){
                    ans++;}
            if(i != grid.size() - 1){
                if(grid[i + 1][j] == '1'){
                    gridcheck.push_back({i + 1, j});}}    
            if(j != grid[0].size() - 1){
                if (grid [i][j + 1] == '1' ){
                    gridcheck.push_back({i, j + 1});}}
            }
        }
    }
return ans;   
}

int main(){

    std::vector<std::vector<size_t>> example {{"1","1","0","0","0"},
                    {"1","1","0","0","0"},
                    {"0","0","1","0","0"},
                    {"0","0","0","1","1"}} ;

    
    std::cout<< numIslands(example)<<std::endl;


    return 0;
}