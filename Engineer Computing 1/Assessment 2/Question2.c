/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 2
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: 8.1.0
  Created  date: 10/12/2021
  Acknowledgement: Lecture slides, www.geeksforgeeks.org
*/
#include <stdio.h>

//a Print array in reverse
void printreverse(int arr[], int size){
    for (int i = size - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//b Calculate and return sum
int sumofeven(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            sum += arr[i];
        }    
    }
    return sum;
}

//c Calculate occurence of a number in array and return it
int occurence(int arr[], int size, int num){
    int occ = 0;
    for (int *p = arr; p < arr + size - 1; p++){
        if(*p == num){
            occ++;
        }
    }
    return occ;
}

//d Find the most occurring value and return it
int mostoccurence(int arr[], int size){
    int swap_count, maxocc = 1, maxoccnum = arr[0], occ = 1;;

    //Sort array in ascending order
    do{
        swap_count = 0;
        for(int *p = arr;p < arr + size - 1; p++){
            int temp = *p;
            if (*p < *(p+1)){
                *p = *(p+1);
                *(p+1) = temp;
                swap_count++;
            }
        }
    } while (swap_count != 0);

    //Find the most occurring value maxoccnum
    for (int *p = arr;p < arr + size; p++){
        if (*p == *(p-1)){
            occ++;
        } else {
            if (occ > maxocc){
            maxocc = occ;
            maxoccnum = *(p-1);
            }
            occ = 1;
        }
    }
    return maxoccnum;
}

//Main function
int main(){
    int arr[] = {3, 7, 7, 8 , 7, 8, 3, 10}, size, num;
    size = sizeof(arr) / sizeof(arr[0]);
    printreverse(arr, size);
    printf("Sum of all even numbers: %d\n",sumofeven(arr, size));
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Occuring frequency of value %d in the array is %d\n", num, occurence(arr, size, num));
    printf("The most occurring value is: %d",mostoccurence(arr, size));
    return 0;
}