#include <stdio.h>
#include <stdlib.h>
int main(){
    int value[20],array_pos;
    for (array_pos=1;array_pos<=20;array_pos++){
        value[array_pos]= rand() % 100;
        printf("%3d",value[array_pos]);
        if (array_pos%10==0){
            printf("\n");
        }
    }
    
}
