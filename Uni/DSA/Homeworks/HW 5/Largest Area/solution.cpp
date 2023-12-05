#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>

const int MAX_STR_LEN = 15000;

std::vector<int> prevSmallerElement(std::vector<int>& streets){
    int size = streets.size();
    std::stack<int> streetStack;
    std::vector<int> nextBiggest(size);
    streetStack.push(-1);
    for (int i = 0; i < size; ++i) {
        while(streetStack.top() != -1 && streets[streetStack.top()] >= streets[i]){
            streetStack.pop();
        }
        nextBiggest[i] = streetStack.top();
        streetStack.push(i);
    }
    return nextBiggest;
}

std::vector<int> nextSmallerElement(std::vector<int>& streets){
    int size = streets.size();
    std::stack<int> streetStack;
    std::vector<int> nextBiggest(size);
    streetStack.push(size);
    for (int i = size - 1; i >= 0; --i) {
        while(streetStack.top() != size && streets[streetStack.top()] >= streets[i]){
            streetStack.pop();
        }
        nextBiggest[i] = streetStack.top();
        streetStack.push(i);
    }
    return nextBiggest;
}

int getLargestSquare(std::vector<int>& streets){
    std::vector<int> prevSmaller = prevSmallerElement(streets);
    std::vector<int> nextSmaller = nextSmallerElement(streets);

    int maxArea = 0;
    for (int i = 0; i < streets.size(); ++i) {
        int currArea = (nextSmaller[i] - prevSmaller[i] - 1) * streets[i];
        if(currArea > maxArea){
            maxArea = currArea;
        }
    }
    return maxArea;
}

int main() {
    int n;
    std::cin>>n;
    std::vector<int> streets(n);
    for (int i = 0; i < n; ++i) {
        std::cin>>streets[i];
    }
    std::cout<<getLargestSquare(streets);

    return 0;
}
