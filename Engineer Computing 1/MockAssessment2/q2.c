#include <stdio.h>
#include <stdlib.h>

//a
void print_first_half(int arr[], int size){
    for (int *p=arr;p<arr+size/2;p++){
        printf("%d ",*p);
    }
    printf("\n");
}

//b
void min_elem(int arr[], int size){
    int min = arr[0];
    for (int i=0;i<size;i++){
        if (min>arr[i]){
            min = arr[i];
        }
    }
    printf("Minimum element: %d\n",min);
}

//c
void average(int arr[], int size){
    int sum=0;
    for (int *p=arr;p<arr+size;p++){
        sum+=*p;
    }
    float avg =(float)sum/size;
    printf("Average: %.2f\n",avg);
}

//d
int closest_elem(int arr[], int size, int num){
    int diff=abs(arr[0]-num), output=0;
    for(int i=0;i<size;i++){
        if (abs(arr[i]-num)<=diff){
            output=arr[i];
            diff=abs(arr[i]-num);
        }
    }
    return output;
}

int main(){
    int arr[]={2, 4, 6, -5, 7, 9, 8, 10}, size, num;
    size = sizeof(arr)/sizeof(arr[0]);
    print_first_half(arr, size);
    min_elem(arr, size);
    average(arr, size);
    printf("Enter a number: ");
    scanf("%d",&num);
    closest_elem(arr, size, num);
    return 0;
}