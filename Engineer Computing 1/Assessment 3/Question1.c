/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 3
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 14/01/2021
  Acknowledgement: Lecture slides 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    //Declare variables
    int num[8], maxeven=0;
    float sum1, sum2;

    //Initiate randomizer
    srand(time(NULL));

    //Randomize array
    for (int i=0;i<8;i++){
        num[i]=rand()%(101)+50;
    }
    printf("Array values: ");
    for (int i=0;i<8;i++){
        printf("%d ",num[i]);
    }
    printf("\n");

    //Largest even number
    for(int i=0;i<8;i++){
        if(num[i]%2==0 && num[i]>maxeven){
            maxeven=num[i];
        }
    }
    printf("Largest even number: %d\n",maxeven);

    //Average of first and second half
    for (int i=0;i<4;i++){
        sum1+=(float)num[i];
    }
    for (int i=4;i<8;i++){
        sum2+=(float)num[i];
    }
    printf("Average of first and second halves: %.2f %.2f", sum1/4, sum2/4);
    return 0;
}
