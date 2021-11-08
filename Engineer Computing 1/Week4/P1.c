#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 10
int main(){
    //Declare variables
    int array[ARRAY_SIZE], pos, count, small;
    //For producing different random numbers each time
    srand(time(NULL));

    //Question 1a
    for (pos=0;pos<ARRAY_SIZE;pos++){
        array[pos]= rand() % (100+1-50)+50;
    }
    printf("\n");

    //Question 1b
    for (pos=0;pos<ARRAY_SIZE;pos++){
        printf("%4d",array[pos]);
    }
    printf("\n");

    //Question 1c
    for (pos=ARRAY_SIZE-1;pos>=0;pos--){
        printf("%4d",array[pos]);
    }
    printf("\n");

    //Question 1d
    count=0;
    for (pos=0;pos<ARRAY_SIZE;pos++){
        if(array[pos]>80){
            printf("%4d",array[pos]);
            count++;
        }
    }
    printf("\n");
    printf("There are %d element(s) larger than 80",count);
    printf("\n");

    //Question 1e
    for (pos=0;pos<ARRAY_SIZE;pos++){
        if(array[pos]<array[pos-1]){
            small=array[pos];
        }
    }
    printf("Smallest element: %4d",small);
    return 0;
}