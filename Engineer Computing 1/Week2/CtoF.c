#include <stdio.h>
int main()
{
    float tempc, tempf;
    //Input temperature in Celsius//
    printf("Enter temperature in Celsius: ");
    scanf("%f",&tempc);
    //Convert to Fahrenheit//
    tempf= tempc/5*9+32;
    printf("Temperature in Fahrenheit: %.2fF",tempf);
    return 0;
}