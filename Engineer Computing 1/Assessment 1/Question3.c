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
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main(){
  //Declare variables
  int arr[SIZE], index, count, max1, max2;
  
  //Function to initialize random numbers
  srand(time(NULL));
  
  //Task a: Randomized array with elements between 40 and 200
  for (index=0;index<SIZE;index++){
    arr[index]= rand() % 161 + 40;
  }
  
  //Task b: Print out elements divisible by 5
  count=0;
  printf("Elements divisible by 5: ");
  for (index=0;index<SIZE;index++){
    if (arr[index]%5==0){
      printf("%4d",arr[index]);
      count++;
    }
  }
  printf("\n");
  printf("There are %d element(s) divisible by 5",count);
  printf("\n");

  //Task c and d: Print out array in 2 columns and the largest value of each
  count=0;
  max1=arr[0];
  max2=arr[1];
  for (index=0;index<SIZE;index++){
    printf("%4d",arr[index]);
    count++;
    if(count%2==0){
      printf("\n");
      //Checking for the largest value of column 2
      if(arr[index]>max2){
        max2=arr[index];
      }
    }
    //Checking for the largest value of column 1
    if(count%2==1){
      if(arr[index]>max1){
        max1=arr[index];
      }
    }
  }
  printf("Largest elements of column 1: %d\n",max1);
  printf("Largest elements of column 2: %d",max2);    
  return 0;
}