/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 2
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 10/12/2021
  Acknowledgement: Lecture slides, Quora, StackOverflow
*/
#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){
	//Declare variables
    char input[SIZE];
	int sum = 0, numstop, wordleft = 0;

	//Input data
	printf("Input a student number and full name:");
	scanf("%[^\n]s", &input);

	//Calculate the sum of student id
	for (int i = 0;i < strlen(input); i++){
		if (input[i] >= '0' && input[i] <= '9'){
			sum += (input[i] - '0');
		}
		if (input[i] == ' ' && input[i-1] >= '0' && input[i-1] <= '9'){
			numstop = i;
			break;//break out of loop when numbers end
		}
	}
	printf("Sum of digits in student number: %d\n", sum);

	//Print name in short
	printf("Name in short: ");
	for (int i = numstop; input[i] != '\0'; i++){
		//Check if there are words left after the current one
		for (int j = i; input[j] != '\0'; j++){
			if (input[j] == ' ' && input[j-1] != ' '){
				wordleft++;
				break;
			}
		}

		//Print initials if there are still more words
		if(input[i-1] == ' ' && input[i] != ' ' && wordleft != 0){
			printf("%c. ", input[i]);
		}

		//Print last name when there are no words left after
		if (wordleft == 0 && input[i] != ' '){
			printf("%c", input[i]);
		}
		wordleft = 0;
	}
	return 0;
}