#include <stdio.h>

int istriangle(int a, int b, int c){
    if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b){
        return 1;
    } else return 0;
}

int main(){
    float a, b, c;
    printf("Enter 3 floats: ");
    scanf("%f %f %f", &a, &b, &c);
    printf(istriangle(a, b, c)?"Yes":"No");
    return 0;
}