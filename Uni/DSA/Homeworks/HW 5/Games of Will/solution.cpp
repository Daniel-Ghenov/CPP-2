#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

size_t daysToFinalStack(std::vector<size_t>& hungers){

    if(hungers.empty()){
        return 0;
    }

    std::stack<size_t> hungerStack;
    for (size_t i = 0; i < hungers.size(); ++i) {
        hungerStack.push(hungers[i]);
    }

    std::stack<size_t> winners;

    winners.push(hungerStack.top());
    hungerStack.pop();

    size_t maxPops = 0;
    size_t currPops = 0;

    while(!hungerStack.empty()){
        while(!winners.empty() && winners.top() > hungerStack.top()){
            winners.pop();
            currPops++;
        }
        if(currPops > maxPops){
            maxPops = currPops;
        }

        winners.push(hungerStack.top());
        currPops = 0;
        hungerStack.pop();
    }

    return maxPops;
}

bool removeHungry(std::vector<size_t>& hungers){
    std::vector<bool> shouldDie(hungers.size(), false);

    int currIdx = 0;
    bool madeChanges = false;
    for (int i = 0; i < hungers.size(); ++i) {
        if(hungers[currIdx] == -1){
            currIdx = i;
            continue;
        }
        if(hungers[i] == -1){
            continue;
        }
        if(hungers[currIdx] < hungers[i]){
            shouldDie[i] = true;
            currIdx = i;
            madeChanges = true;
        }else{
            currIdx = i;
        }
    }
    for (int i = 0; i < shouldDie.size(); ++i) {
        if(shouldDie[i]){
            hungers[i] = -1;
        }
    }

    return madeChanges;
}


size_t daysToFinal(std::vector<size_t>& hungers){


    size_t days = 0;
    while(removeHungry(hungers) && days < 50){
        days++;
    }
    if(days == 50){
        return daysToFinalStack(hungers);
    }
    return days;
}


int main() {
    size_t n;
    std::cin>>n;
    std::vector<size_t> vec(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin>>vec[i];
    }
    std::cout<<daysToFinal(vec);
    return 0;
}