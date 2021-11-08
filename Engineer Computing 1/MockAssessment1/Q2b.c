#include <stdio.h>

int main() {
    int input, row, value, space;
    do{
        printf("Enter an integer between 0 and 10: ");
        scanf("%d", &input);
        if (input>10 || input<0) {
            printf("Please enter a number in the specified range!\n");
        }
    } while (input>10 || input<0);
    for(row=1;row<=input;row++){
        if (input<8 && row == 1){
            printf("%3d",row);
        }
        if (row>1){
            for (value=row;value>0;value--){
                printf("%3d",value);
            }
            for (space=input-row-1;space>0;space--){
                printf("   ");
            }
            
        }
        if (input>=8){
            if (row==1){
                for (value=row;value<=input;value++){
                    printf("%3d",value);
                }
            }
            if (row>1 && row<input){
                printf("%3d",input-row+1);
            }
        }
        printf("\n");
    }
    return 0;
}
