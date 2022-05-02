#include <stdio.h>
#include <ctype.h>
#include <string.h>
typedef struct{
    int day;
    int month;
    int year;
} date;
//a
int numofalph (char str[]){
    int count;
    for (int i=0;str[i]!='\0';i++){
        if(isalpha(str[i])){
            count++;
        }
    }
    return count;
}

//b
float avgofdigit(char str[]){
    int sum, numcount=0;
    for (int i=0;str[i]!='\0';i++){
        if (isdigit(str[i])){
            sum+=(str[i]-'0');
            numcount++;
        }
    }
    float avg=(float)sum/numcount;
    return avg;
}
//c
void removenondigit(char str[]){
    char out[50], outi=0;
    for (int i=0;str[i]!='\0';i++){
        if(isdigit(str[i])){
            out[outi]=str[i];
            outi++;
        }
    }
    out[outi]='\0';
    printf("%s\n",out);
    strcpy(str,out);
    str[outi]='\0';
}

//d
int daynum(date a){
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31}, out=a.day;
    for (int i=0;i<a.month-1;i++){
        out+=month[i];
    }
    return out;
}

//main
int main(){
    char str[50];
    date a;
    printf("Enter a string: ");
    scanf("%[^\n]s", &str);
    printf("There are %d alphabetical character(s)\n",numofalph(str));
    printf("Average of digits: %.2f\n",avgofdigit(str));
    removenondigit(str);
    printf("%s\n",str);
    printf("Enter a date with dd/mm/yyyy format: ");
    scanf("%2d/%2d/%4d",&a.day, &a.month, &a.year);
    printf("Day number %d",daynum(a));
    return 0;
}