#include <stdio.h>
int main()
{
    int num, d1, d2, d3, sum;
    printf("Enter a 3-digit number: ");
    scanf("%d",&num);
    d1 = num % 100 % 10;
    d2 = (num - d1) % 100 / 10;
    d3 = (num - d1 - d2 * 10) / 100;
    sum = d1 + d2 + d3;
    printf("Sum of 3 digits: %d",sum);
    return 0;
}