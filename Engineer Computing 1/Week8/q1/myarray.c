#include <stdio.h>
#include "myarray.h"
void printarray (int array[], int size) {
    printf("Print Array element in normal order: \n");
    for (int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void printarrayreverse (int array[], int size) {
    printf("Print Array element in reverse order: \n");
    for (int i=size-1;i>=0;i--){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void arraymax (int array[], int size) {
    printf("Array maximum element: ");
    int max=array[0];
    for (int i=0;i<size;i++){
        if (max<array[i]){
            max = array[i];
        }
    }
    printf("%d\n",max);
}

int isintegerinarray(int array[], int size, int find){
    for (int i=0;i<size;i++){
        if(find==array[i]){
            return 1;
            break;
        } else {
            return 0;
        }
    }
}