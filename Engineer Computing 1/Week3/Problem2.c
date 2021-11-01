#include <stdio.h>
int main() {
    int num, sum = 0, numcount = 0;
    do {
        printf("Enter a positive integer: ");
        scanf("%d",&num);
        if (num>0) {
            sum += num;
            numcount++;
        }
    } while (num>0);
    printf ("Here's the sum of all the positive integer: %d\n",sum);
    printf("There are %d positive integer(s)",numcount);
    return 0;
}