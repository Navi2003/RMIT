/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 3
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 14/01/2021
  Acknowledgement: Lecture slides, deviot.vn
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    int id;
    int score;
    char name[];
} student;

void converttostudent(char stu[]){
    student output;
    int num=1000000, i, j=0;
    char *tokenid = strtok(stu, "  ");
    for (i=0;tokenid[i]!='\0';i++){
        output.id+=((tokenid[i]-'0')*num);
        num/10;
    }
    output.id+=tokenid[i];
    printf("%d",output.id);
    for (i;!isspace(stu[i]) && !isspace(stu[i+1]) &&!isspace(stu[i+2]);i++){
        output.name[j]=stu[i];
    }
    output.name[j]='\0';
    printf("%s",output.name);
}

int main(){
    char stu1[50], stu2[50], stu3[50];
    student stu[3];
    printf("Enter student info: ");
    scanf("\n%[^\n]s",&stu1);
    converttostudent(stu1);
    return 0;
}