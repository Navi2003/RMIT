#include <stdio.h>

void printdigits(int num){
    int arr[10], i;
    if (num==0){
        printf("0");
    } else {
        for (i = 0; num>0; i++){
            arr[i] = num % 10;
            num /= 10;
        }
        i-=1;
        for (i; i >= 0; i--){
            printf("%d ", arr[i]);
        }
    }
}

int sumofdigits(int num){
    int sum=0;
    if (num<10){
        return sum+=num;
    }
    sum+=num%10;
    return sum + sumofdigits(num/10);
}


int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printdigits(num);
    printf("\n");
    printf("Sum of digits: %d",sumofdigits(num));
    return 0;
}