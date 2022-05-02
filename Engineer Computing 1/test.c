#include <stdio.h>

int sumofelem(int arr[], int size){
    int sum;
    if(size==1){
        return arr[0];
    }
    return arr[size-1]+sumofelem(arr,size-1);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    printf("Sum: %d",sumofelem(arr, 4));
    return 0;
}