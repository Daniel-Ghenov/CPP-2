#include <vector>
#include <iostream>
#include <algorithm>

bool isSorted(std::vector<int>& arr){
    int currNum = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < currNum)
            return false;
        currNum = arr[i];
    }
    return true;
}

int numDaysToSort(std::vector<int>& arr){
    if(isSorted(arr))
        return 0;
    int numDays = arr.size();
    int daysToRemove = 0;
    int smallest = arr[0];
    int currNum = arr[0];
    bool counting = true;
    for(int i = 1; i < numDays; i++){
        if(arr[i] >= currNum && counting){
            currNum = arr[i];
            daysToRemove++;
        }else{
            counting = false;
        }
        if(arr[i] < smallest || (arr[i] == smallest && arr[i] < currNum)){
            daysToRemove = 0;
            break;
        }
    }
    numDays -= daysToRemove;
    daysToRemove = 0;
    counting = true;
    int largest = arr[arr.size() - 1];
    currNum = largest;
    for(int i = arr.size() - 2; i >= 0; i--){
        if(arr[i] <= currNum && counting){
            currNum = arr[i];
            daysToRemove++;
        }else{
            counting = false;
        }
        if(arr[i] > largest || (arr[i] == largest && arr[i] > currNum)){
            daysToRemove = 0;
            break;
        }
    }
    return numDays - daysToRemove;

}

int main() {
    int size = 0;
    std::cin>>size;
    std::vector<int> arr(size);
    for(int i = 0; i < size; i++){
        std::cin>>arr[i];
    }
    std::cout<<numDaysToSort(arr);
    return 0;
}
