#include <stdio.h>
#define ARRAY_SIZE 14
int main(){
    char arr[] ={'R', 'M', 'I', 'T', 'U', 'n', 'i', 'v', 'e', 'r', 's', 'i', 't', 'y'};
    int a,b,c,swap_count;
    do{
        swap_count=0;
        for(a=0;a<ARRAY_SIZE;a++){
            c=arr[a];
            if (arr[a+1]<arr[a]){
                arr[a]=arr[a+1];
                arr[a+1]=c;
                swap_count++;
            }
        }
    } while (swap_count!=0);
    for(a=0;a<ARRAY_SIZE;a++){
        printf("%3c",arr[a]);
    }
    return 0;
}