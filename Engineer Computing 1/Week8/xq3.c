#include <stdio.h>

int lineareq(int a, int b){
    if (a!=0){
        printf("x = %d\n",-b/a);
        return 1;
    } else if (b==0){
            printf("x is the set of all integers\n");
            return 1;
        } else {
                return 0;
            }
}

int main(){
    int a, b;
    printf("ax + b = 0\n");
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    printf(lineareq(a, b)?"Solved":"Unsolvable");
    return 0;
}