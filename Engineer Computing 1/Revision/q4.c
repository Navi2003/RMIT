#include <stdio.h>

int main(){
    int arr[5], switchtime, temp;
    for (int i=0; i<5; i++){
        printf("Enter element %d: ",i);
        scanf("%d",&arr[i]);
    }
    do{
        switchtime=0;
        for (int i=0; i<4; i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                switchtime++;
            }
        }
    } while (switchtime != 0);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}