#include <stdio.h>
int main(){
    int value = 33, count = 0;
    while (value<127){
    putchar(value);
    printf(" ");
    value++;
    count++;
        if (count%15==0){
            printf("\n");
        }
    }
    return 0;
}