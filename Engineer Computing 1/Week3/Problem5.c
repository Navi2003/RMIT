#include <stdio.h>
int main(){
    int a, b;
    printf("Enter an integer between 1 and 15: ");
    scanf("%d",&a);
    for (a;a>0;a--){
        for(b=a;b>1;b--){
            printf("%3d",b);
        }
        for(b;b<=a;b++){
            printf("%3d",b);
        }
        printf("\n");
    }
    return 0;
}