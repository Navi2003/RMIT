#include <stdio.h>
int main(){
    //Declare variables necessary
    int a, b;
    
    //Input integer
    printf("Enter an integer between 1 and 15: ");
    scanf("%d",&a);

    //Nested loop to create a half pyramid, highest value decreasing each loop
    for (a;a>0;a--){
        //Loop for printing from highest value to 1
        for(b=a;b>1;b--){
            printf("%3d",b);
        }
        //Loop for printing from 2 o highest value
        for(b;b<=a;b++){
            printf("%3d",b);
        }
        printf("\n");
    }
    return 0;
}