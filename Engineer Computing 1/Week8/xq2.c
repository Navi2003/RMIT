#include <stdio.h>

void digitreverse(int a){
    while(1){
        printf("%d",a%10);
        if(a<10){
            break;
        }
        a/=10;
    }
}

int main(){
    int num;
    printf("Enter an integer: ");
    scanf("%d",&num);
    digitreverse(num);
    return 0;
}