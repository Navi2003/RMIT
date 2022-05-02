/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 2
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 10/12/2021
  Acknowledgement: Lecture slides 
*/
#include <stdio.h>
int main(){
	//Declare variables
	char str[40];
	int len, i;

	//Input string and calculate length
    printf("Enter an string: ");
	scanf("%[^\n]s", &str);
	len = sizeof(str) / sizeof(str[0]);

	//Loop to check if not vowels then replace by space
	for (i = 0; i < len; i++){
		if (str[i] != 'a' && str[i] != 'e' && str[i] != 'u' && str[i] != 'e' && str[i] != 'o'){
			str[i] = ' ';
		}
	}
	str[i] = '\0';
	printf("%s",str);
	return 0;
}