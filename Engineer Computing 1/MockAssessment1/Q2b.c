#include <stdio.h>

int main() {
    int input, row, val, space;
    do{
        printf("Enter an integer between 0 and 10: ");
        scanf("%d", &input);
        if (input>10 || input<0) {
            printf("Please enter a number in the specified range!\n");
        }
    } while (input>10 || input<0);
    for(row=1;row<=input;row++){
			for (val=row;val>0;val--){
				printf("%2d ",val);
		}
		if (input>=8){
			if (row==1){
				for (val=2;val<=input;val++){
					printf("%2d ",val);
				}
			}
			for (space=input-row-1;space>0;space--){
				printf("   ");
			}
			if(row>1 && row<input){
			printf("%2d ",input+1-row);
			}
		}
        printf("\n");
    }
    return 0;
}
