#include <stdio.h>

int main() {
    int input, row, value;
    do{
        printf("Enter an integer between 0 and 10: ");
        scanf("%d", &input);
        if (input>10 || input<0) {
            printf("Please enter a number in the specified range!\n");
        }
    } while (input>10 || input<0);
    for(row;row<=input;row++){
        for (value=row;value>0;value--){
            printf("%3d",value);
        }
        printf("\n");
    }
    return 0;
}
