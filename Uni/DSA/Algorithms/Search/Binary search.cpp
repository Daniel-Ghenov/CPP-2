int binarySearch(int* arr, size_t size, int find){
    int min = 0, max = size;
    while(min != max){
        int mid = (min + max) / 2;
        if(arr[mid] == find)
            return mid;
        else if(arr[mid] < find){
            min = mid + 1;
        }else{
            max = mid - 1;
        }
    }
    return -1;
}
int recursBinarySearch(int* arr ,int find, size_t left , size_t right){
    size_t mid = (left + right) / 2;
    if( arr[mid] == find)
        return mid;
    else if(arr[mid] > right){
        return recursBinarySearch(arr, find, left, mid - 1);
    }
    else    
        return recursBinarySearch(arr, find, mid + 1, right);

}
int exponentialSearch(int* arr, size_t size, int find){
    if(size == 0){
        return -1;
    }
    int bound = 1;
    while(bound < size && arr[bound] > find )
        bound *= 2;

    return recursBinarySearch(arr, find, bound / 2, bound);

}
