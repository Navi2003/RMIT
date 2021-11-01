#include <stdio.h>
int main(){
    int a, b, c, d, e;
    do {
        printf("Enter an integer between 1 and 15: ");
        scanf("%d",&a);
    } while(a<1 || a>15);
    d=a;
    for (b=1;b<=a;b++) {
        for(c=d;c>1;c--) {
            printf("   ");
        }
        for(e=b;e>1;e--) {
            printf("%3d",e);
        }
        for(e;e<=b;e++) {
            printf("%3d",e);
        }
    printf("\n");
    d--;
    }
    return 0;
}