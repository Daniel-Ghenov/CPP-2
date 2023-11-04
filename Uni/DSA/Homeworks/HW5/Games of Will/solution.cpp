#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

int daysToFinal(std::vector<int>& hungers){

    if(hungers.empty()){
        return 0;
    }

    std::stack<int> hungStack;
    for (int i = 0; i < hungers.size(); ++i) {
        hungStack.push(hungers[hungers.size() - i - 1]);
    }
    std::stack<int> winners;
    int maxPops = 0;
    int currPops = 0;

    winners.push(hungStack.top());
    hungStack.pop();
    while(!hungStack.empty()){
        while(winners.top() > hungStack.top() ){
            winners.pop();
            currPops++;
        }
        if(currPops > maxPops){
            maxPops = currPops;
        }

        winners.push(hungStack.top());
        currPops = 0;
        hungStack.pop();
    }

    return maxPops;
}



int main() {
    int n;
    std::cin>>n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin>>vec[i];
    }
    std::cout<<daysToFinal(vec);
    return 0;
}