#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, ans;
    //Input x and y//
    printf("Enter the value of X: ");
    scanf("%d",&x);
    printf("Enter the value of Y: ");
    scanf("%d",&y);
    //Calculate X to the power of Y//
    ans = pow(x,y);
    printf("The value of X to the power of Y is: %d",ans);
    return 0;
}