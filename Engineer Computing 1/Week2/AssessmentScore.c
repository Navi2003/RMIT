#include <stdio.h>
int main()
{
    float asresult, as1, as2, as3;
    printf("Enter 3 assessment scores: ");
    scanf("%f %f %f", &as1, &as2, &as3);
    asresult = (as1 * 30 + as2 * 30 + as3 * 40)/100;
    printf("Final result: %.2f",asresult);
    return 0;

}