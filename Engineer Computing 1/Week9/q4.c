#include <stdio.h>

//a
int sum1tonum(int num){
    if (num==1){
        return 1;
    }
    return num + sum1tonum(num-1);
}

//b
int printarray(int arr[], int i, int size){
    if (i == size - 1){
        printf("%d",arr[i]);
        return 1;
    }
    printf("%d ",arr[i]); 
    return printarray(arr, i+1, size);
}

//c





int main() {
    int num, arr[]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum from 1 to number: %d\n",sum1tonum(num));
    printarray(arr, 0, size);
    return 0;
}