#include <iostream>
#include <cstring>

int max_elem(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 7, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << max_elem(arr, size);
    return 0;
}


/*
#include <iostream>

int max_elem(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++ ){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}


int main(){
    int arr[]= {1, 2, 3, 4, 5};
    std::cout << "Highest elem: " << max_elem(arr, 5);
    return 0;
}
*/