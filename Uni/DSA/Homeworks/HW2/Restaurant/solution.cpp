#include <vector>
#include <iostream>
#include <algorithm>

int numDaysToSort(std::vector<int> &arr)
{
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());

    size_t daysToRemove = 0;
    for(int i = 0; i < arr.size(); i++){
        if(sorted[i] == arr[i]){
            daysToRemove++;
        }
        else{
            break;
        }
    }
    if(daysToRemove == arr.size())
        return 0;

    for(int i = arr.size() - 1; i >= 0; i--){
        if(sorted[i] == arr[i]){
            daysToRemove++;
        } else{
            break;
        }
    }
    return arr.size() - daysToRemove;

}

int main()
{
    int size = 0;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << numDaysToSort(arr);
    return 0;
}
