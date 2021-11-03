#include <stdio.h>
int main() {
    //Declare variables for input integers, the sum and the number of integer//
    int num, sum = 0, numcount = 0;
    
    //Input integers, repeat until user enter a negative integer//
    do {
        printf("Enter a positive integer: ");
        scanf("%d",&num);
        if(num<0){
            break;
        }
        if (num>0) {
            sum += num;
            numcount++;
        }
    } while (num>=0);
    
    //Print the sum and the number of positive integers//
    printf ("Here's the sum of all the positive integer: %d\n",sum);
    printf("There are %d positive integer(s)",numcount);
    return 0;
}