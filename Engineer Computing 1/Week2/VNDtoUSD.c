#include <stdio.h>

int main()
{
    float usd, vnd;
    //Input VND//
    printf("Input your money in VND: ");
    scanf("%f",&vnd);
    //Convert to USD//
    usd = vnd/23150;
    printf("Here's your money in USD: $%.2f",usd);
    return 0;
}