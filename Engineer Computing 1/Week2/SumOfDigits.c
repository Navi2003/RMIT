#include <stdio.h>
int main()
{
    int num, sum;
    printf("Enter a 3-digit number: ");
    scanf("%d",&num);
    sum = num / 100 + num % 100 / 10 + num % 100 % 10;
    printf("Sum of 3 digits: %d",sum);
    return 0;
}