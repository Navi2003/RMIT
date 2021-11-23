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
  int num, row, val, blank;
  
  //Prompt the user to enter a number between 1 and 10
  //Print out an error and repeat if the number isnt between 1 and 10
  do {
    printf("Enter a number between 1 and 10: ");
    scanf("%d",&num);
    if (num<1 || num>10){
      printf("Invalid number. Please enter a number in the specified range.\n");
    }
  } while (num<1 || num>10);

  //Print out pattern
  for (row=1;row<=num;row++){
    
    //Even numbers
    if(num%2==0){
      for (val=1;val<=num-row+1;val++){
        printf("%3d",val);
      }
    }
    
    //Odd numbers
    if(num%2==1){
      //First row, print highest to lowest and vice versa
      if(row==1){
        for (val=num;val>1;val--){
          printf("%3d",val);
        }
        for (val=1;val<=num-row+1;val++){
        printf("%3d",val);
        }
        printf("\n");
        continue;//Skip the rest and go to row 2
      }
      
      //From second row onwards
      //Print out blanks
      for(blank=row-1;blank>0;blank--){
        printf("   ");
      }
      //Print the number on the left when it is not the last row
      if (row<num){
        printf("%3d",num-row+1);
      }
      //Print out blanks
      for(blank=num-row-1;blank>0;blank--){
        printf("   ");
      }
      //Print out left side
      for (val=1;val<=num-row+1;val++){
        printf("%3d",val);
      }
    }
    printf("\n");
  }   
  return 0;
}