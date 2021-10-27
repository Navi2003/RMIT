#include <stdio.h>
int main()
{
    int min, hr, min2;
    printf("Enter time in minutes: ");
    scanf("%d",&min);
    hr = min/60;
    min2 = min%60;
    printf("Here's your time: %d Hour(s) %d Minute(s)",hr ,min2);
    return 0;
}