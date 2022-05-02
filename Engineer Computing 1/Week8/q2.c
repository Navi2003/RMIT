#include <stdio.h>

int intpow(int base, int exp){
    int value=base;
    for (int i=1;i<=exp-1;i++){
        value*=base;
    }
    return value;
}

int main(){
    int b, e;
    printf("Base: ");
    scanf("%d",&b);
    printf("Exponent: ");
    scanf("%d",&e);
    printf("Value: %d",intpow(b,e));
    return 0;
}