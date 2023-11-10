#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

void popAll(std::deque<int>& fight, int temp){

    while(!fight.empty() && fight.back() < abs(temp)){
        fight.pop_back();
    }
    if(fight.empty()){
        std::cout<<temp<<' ';
        return;
    }
    if(fight.back() == abs(temp)){
        fight.pop_back();
    }
}
int main() {

    int n;
    std::cin>>n;
    std::deque<int> fight;
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin>>temp;

        if(fight.empty() && temp < 0){
            std::cout<<temp<<' ';
            continue;
        }
        if(fight.empty()){
            fight.push_back(temp);
            continue;
        }
        if(temp > 0){
            fight.push_back(temp);
            continue;
        }
        if(fight.back() <= abs(temp)){
            popAll(fight, temp);
        }
    }
    while(!fight.empty()){
        std::cout<<fight.front()<<' ';
        fight.pop_front();
    }

    return 0;
}