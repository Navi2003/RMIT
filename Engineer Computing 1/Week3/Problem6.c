#include <stdio.h>
int main(){
    //Declare variables necessary
    int num, row, space, value;
    
    //Enter an integer, repeat if not in specified range
    do {
        printf("Enter an integer between 1 and 15: ");
        scanf("%d",&num);
    } while(num<1 || num>15);
    
    //Nested loop to create a pyramid, highest value increasing each loop
    for (row=1;row<=num;row++) {
        //Loop for printing blank spaces, decreasing each loop
        for(space=num-row;space>0;space--) {
            printf("   ");
        }
        //Loop for printing highest value to one
        for(value=row;value>1;value--) {
            printf("%3d",value);
        }
        //Loop for printing 2 to highest value
        for(value;value<=row;value++) {
            printf("%3d",value);
        }
    printf("\n");
    }
    return 0;
}