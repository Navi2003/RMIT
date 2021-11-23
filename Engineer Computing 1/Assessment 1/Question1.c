/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 1
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 13/11/2021
  Acknowledgement: Lecture slides, StackOverflow
  */
#include <stdio.h>

int main(){
  //Declare variables
  int in, out_day1, out_hour;
  float out_day2;

  //Input the total hours
  printf("Enter total hours: ");
  scanf("%d",&in);

  //Calculate and print out input in only days
  out_day2 = (float) in / 24;
  printf("It is %.2f day(s)\n",out_day2);

  //Calculate and print out input in days and hours
  out_day1 = in / 24;
  out_hour = in % 24;
  printf("which is %d day(s) and %d hour(s)",out_day1,out_hour);   
  return 0;
}