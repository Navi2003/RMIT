#include <stdio.h>
int main(){
    //Declare variables necessary
    int a, b, c, d, e;
    
    //Enter an integer, repeat if not in specified range
    do {
        printf("Enter an integer between 1 and 15: ");
        scanf("%d",&a);
    } while(a<1 || a>15);
    d=a;
    //Nested loop to create a pyramid, highest value increasing each loop
    for (b=1;b<=a;b++) {
        //Loop for printing blank spaces, decreasing each loop
        for(c=d;c>1;c--) {
            printf("   ");
        }
        //Loop for printing highest value to one, highest value increasing each loop
        for(e=b;e>1;e--) {
            printf("%3d",e);
        }
        //Loop for printing 2 to highest value, highest value increasing each loop
        for(e;e<=b;e++) {
            printf("%3d",e);
        }
    printf("\n");
    d--;
    }
    return 0;
}