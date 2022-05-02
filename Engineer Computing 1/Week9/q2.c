#include <stdio.h>

void isleapyear(int yr){
    if(yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0)) {
        printf("%d is a leap year", yr);
    } else printf("%d is not a leap year", yr);
}

int main(){
    int yr;
    printf("Enter year: ");
    scanf("%d",&yr);
    isleapyear(yr);
    return 0;
}