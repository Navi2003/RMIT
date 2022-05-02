#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int arr[10], n, switchcount, temp;
    printf("Enter an integer: ");
    scanf("%d",&n);
    srand(time(NULL));
    for (int i=0;i<10;i++){
        arr[i]=rand()%(n+1);
    }
    for (int i=0;i<10;i++){
        printf("%2d ",arr[i]);
    }
    printf("\n");
    do {
        switchcount=0;
        for (int i=0;i<9;i++){
            if (arr[i+1]<arr[i]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                switchcount++;
            }
        }
    } while (switchcount!=0);
    for (int i=0;i<10;i++){
        printf("%2d ",arr[i]);
    }
    return 0;
}