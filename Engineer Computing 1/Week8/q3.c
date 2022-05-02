#include <stdio.h>

int primer(int num){
    if (num%2==0 && num!=2 || num==1){
        return 0;
    } else {
        for (int i=3;i<=num;i+=2){
            if (num % i==0 && num != i){
                return 0;
                break;
            } else return 1;
        }
    }
}

int main(){
    int num;
    printf("Number: ");
    scanf("%d",&num);
    printf(primer(num)?"Prime":"Not prime");
    return 0;
}