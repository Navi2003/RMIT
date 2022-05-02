/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 3
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 14/01/2021
  Acknowledgement: Lecture slides 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50

//a Print alphabetical
void printalpha(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(isalpha(str[i])){
            printf("%c",str[i]);
        }
    }
    printf("\n");
}

//b Sum of odd number
int sumofodd(char str[]){
    int sum=0;
    for(int i=0;str[i]!='\0';i++){
        if(isdigit(str[i])){
            if((str[i]-'0') % 2 == 1){
            sum+=(str[i]-'0');
            }
        }
    }
    return sum;
}

//c All sub characters found in main
int issubcharinmain(char main[], char sub[]){
    int count;
    for (int i=0;sub[i]!='\0';i++){
        count=0;
        for (int j=0;main[j]!='\0';j++){
            if(isalpha(main[j])){
                if (main[j]==sub[i] || main[j]==sub[i]-32 || main[j]==sub[i]+32){
                    count++;
                }
            } else if(main[j]==sub[i]){
                count++;
            }
        }
        if(count==0){
            return 0;
        }
    }
    return 1;
}

//d Wildcard sub in main
int issubwildcard(char main[], char sub[]){
    int matchcount;
    for (int i=0;main[i]!='\0';i++){
        matchcount=0;
        for (int j=0;sub[j]!='\0';j++){
            if (sub[j]=='*'){
                continue;
            }
            if (sub[j]==main[i+j]){
                matchcount++;
            }
        }
        if(matchcount==strlen(sub)-1){
            return 1;
        }
    }
    return 0;
}


int main(){
    char str[SIZE], sub[SIZE], subwildcard[SIZE];
    printf("Enter a string: ");
    scanf("\n%[^\n]s",&str);
    printf("Enter sub string: ");
    scanf("\n%[^\n]s",&sub);
    printf("Enter sub string with one wild card '*': ");
    scanf("\n%[^\n]s",&subwildcard);
    printalpha(str);
    printf("Sum of odd numbers: %d\n",sumofodd(str));
    printf("%sll characters of sub is found in main.\n",issubcharinmain(str,sub)?"A":"Not a");
    printf("Sub string with wild card %s with main string.\n",issubwildcard(str,subwildcard)?"matches":"doesn't match");
    return 0;
}