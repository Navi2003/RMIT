#include <stdio.h>

typedef struct{
    int hour;
    int min;
    int sec;
}time;

float cvtohr(time t){
    return t.hour + (float)t.min/60 + (float)t.sec/3600;
}

int main(){
    time t1, t2, t3, t4;
    printf("Enter time 1: ");
    scanf("%2d:%2d:%2d", &t1.hour, &t1.min, &t1.sec);
    printf("Enter time 2: ");
    scanf("%2d:%2d:%2d", &t2.hour, &t2.min, &t2.sec);
    printf("Enter time 3: ");
    scanf("%2d:%2d:%2d", &t3.hour, &t3.min, &t3.sec);
    printf("Enter time 4: ");
    scanf("%2d:%2d:%2d", &t4.hour, &t4.min, &t4.sec);
    printf("Time difference between t1 and t2: %.2f", cvtohr(t1)-cvtohr(t2));
    time arr[]={t1, t2, t3, t4}, latest=t1;
    int latei;
    for (int i=0;i<4;i++){
        if(cvtohr(latest)<cvtohr(arr[i])){
            latest=arr[i];
        }
    }
    printf("Latest time: %d:%d:%d", latest.hour, latest.min, latest.sec);
    return 0;
}