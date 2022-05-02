#include <stdio.h>

int sumofarr(int arr[], int size){
    if(size==1){
        return arr[0];
    }
    return arr[size-1]+sumofarr(arr,size-1);
}

int main(){
    int arr[]={1,2,3,4};
    printf("%d",sumofarr(arr,4));
    return 0;
}