#include <stdio.h>
#define ARRAY_SIZE 5
int main(){
    int array[ARRAY_SIZE],sorted[ARRAY_SIZE], pos, check, small, small_pos;
    //Question 2a
    for (pos=0;pos<ARRAY_SIZE;pos++){
        printf("Enter the value of array[%d]: ",pos);
        scanf("%d",&array[pos]);
    }

    //Question 2b: Selection sort
    
    for (pos=0;pos<ARRAY_SIZE;pos++){
        small=array[pos];small_pos=pos;
        for (check=pos+1;check<ARRAY_SIZE;check++){
            if(array[check]<small){
                small=array[check];
                small_pos=check;
            }
        }
        if (small_pos!=pos){
            array[small_pos]=array[pos];
            array[pos]=small;
        }
    }
    for (pos=0;pos<ARRAY_SIZE;pos++){
        printf("%3d",array[pos]);
    }

    return 0;
}