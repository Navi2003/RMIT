#include <stdio.h>
#include "myarray.h"
#define SIZE 5

int main(){
    int arr[SIZE] = {12, 7, -3, 4, 1};
    printarray(arr, SIZE);
    printarrayreverse(arr, SIZE);
    arraymax(arr, SIZE);
    int find;
    printf("In array? ");
    scanf("\n%d",&find);
    printf(isintegerinarray(arr, SIZE, find)?"Yes\n":"No\n");
    return 0;
}