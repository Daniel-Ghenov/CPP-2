#include <vector>
#include <iostream>
#include <algorithm>

int numDoubles(std::vector<int>& students, int d){
    int num = 0;

    for(size_t i = 0; i < students.size(); i++){
        int studentProject = students[i];
        bool found = std::binary_search(students.begin(), students.end(),studentProject - d);
        if(found){
            num++;
        }
    }
    return num;
}

int main() {
    int n, d;
    std::cin>>n>>d;
    std::vector<int> students(n);
    for(size_t i = 0; i < n; i++){
        std::cin>>students[i];
    }
    std::sort(students.begin(), students.end());
    std::cout<<numDoubles(students, d);

    return 0;
}