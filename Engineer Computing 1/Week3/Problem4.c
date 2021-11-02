#include <stdio.h>
int main() {
    //Declare variables for the column and row
    int column, row, prod;
    
    //Print out the top part first
    printf(" x |   1   2   3   4   5   6   7   8   9  10\n");
    printf("--------------------------------------------\n");
    
    //Loop for creating new row
    for (row = 1;row<=10;row++) {
        //Print out the row numbers for each row
        if (column == 0) {
            printf("%2d |",row);
        }
        //Loop for printing out the product of column and row
        for (column = 1;column <= 10;column++) {
                prod = column * row;
                printf("%4d",prod);
            }
        column = 0;
        printf("\n");
    }
    return 0;
}
