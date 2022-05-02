#include <stdio.h>

int main(){
    int num = 11, row, column;
    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num < 1 || num > 10){
            printf("Invalid\n");
        }
    } while (num < 1 || num > 10);
    printf(" x |");
    for (int i=1; i <= num; i++){
        printf("%4d", i);
    }
    printf("\n");
    for (int i=1; i <= num; i++){
        printf("-----");
    }
    printf("\n");
    for (row=1; row<=num; row++){
        printf("%2d |",row);
        for (column=1; column<=num; column++){
            printf("%4d",row*column);
        }
        printf("\n");
    }
    return 0;
}