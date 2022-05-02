#include <stdio.h>

typedef struct{
    int hour;
    int min;
    int sec;
}time;

float converttohour(time t){
    return t.hour+(float)t.min/60+(float)t.sec/3600;
}

int main(){
    time t1,t2,t3,t4;
    printf("Enter time 1: ");
    scanf("\n%d:%d:%d", &t1.hour, &t1.min, &t1.sec);
    printf("Enter time 2: ");
    scanf("\n%d:%d:%d", &t2.hour, &t2.min, &t2.sec);
    printf("Time difference: %.2f hour(s)\n",converttohour(t1)-converttohour(t2));
    printf("Enter time 1: ");
    scanf("\n%d:%d:%d", &t3.hour, &t3.min, &t3.sec);
    printf("Enter time 2: ");
    scanf("\n%d:%d:%d", &t4.hour, &t4.min, &t4.sec);
    time timearr[]={t1,t2,t3,t4};
    int maxi;
    float maxtime=converttohour(t1);
    for (int i=0;i<4;i++){
        if (converttohour(timearr[i])>maxtime){
            maxtime=converttohour(timearr[i]);
            maxi=i;
        }
    }
    printf("Latest time: %d:%d:%d", timearr[maxi].hour,timearr[maxi].min,timearr[maxi].sec);
    return 0;
}