

int ternarySearch(int* arr, size_t size, int find){

    int min = 0;
    int max = size - 1;

    while(min <= max){
        int q1 = min + (max - min)/3; // 2/3 min + 1/3 max
        int q2 = min - (max - min/3); // 4/3 min - 1/3 max
        if(arr[q1] == find)
            return q1;
            
        else if(arr[q2] == find)
            return q2;

        else if(find < arr[q1])
            max = q1 - 1;

        else if(find > arr[q2]){

            min = q2 + 1;
        }
        else             
            min = q1 + 1;
            max = q2 - 1;
    }

    return -1;
}
int recursTernarySearch(int* arr, size_t left, size_t right, int find){

    size_t q1 = left + (left - right)/3;
    size_t q2 = left - (left - right)/3;

    if(arr[q1] == find)
        return q1;
    
    else if(arr[q2] == find)
        return q2;
    
    else if(find < arr[q1])
        return recursTernarySearch(arr, left, q1 - 1, find);

    else if(find > arr[q2])
        return recursTernarySearch(arr, q2 + 1, right, find);

    else
        return recursTernarySearch(arr, q1 + 1, q2 - 1, find);

}