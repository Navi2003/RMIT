#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int value[20],array_pos, count=0;
    srand(time(NULL));
    for (array_pos=1;array_pos<=20;array_pos++){
        value[array_pos]= rand() % 100;
        if (value[array_pos]>=50){
            printf("%3d",value[array_pos]);
            count++;
        }
    }
    printf("\n");
    printf("There is/are %d mark(s) between 50 and 100",count);
    return 0;
}