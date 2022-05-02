#include <stdio.h>

int main(){
    int arr[] = {12, 7, -3, 4, 1};
    int *p= arr, *p2=arr+4, sum, temp;
    
    //a
    for (p;p<=p2;p++){
        printf("%d ",*p);
    }
    printf("\n");

    //b
    p = arr;
    for (p2;p2>=p;p2--){
        printf("%d ",*p2);
    }
    printf("\n");

    //c
    p = arr;
    p2 = arr + 4;
    for (p;p<=p2;p++){
        sum+=*p;
    }
    printf("%d \n",sum);

    //d
    int *p3=arr+4;
    p = arr;
    for (p;p<=p2-3;p++){
        temp = *p;
        *p = *p3;
        *p3 = temp;
        p3--;
    }
    p = arr;
    for (p;p<=p2;p++){
        printf("%d ",*p);
    }
    return 0;
}