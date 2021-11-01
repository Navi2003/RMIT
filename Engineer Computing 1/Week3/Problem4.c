#include <stdio.h>
int main() {
    int column, row, prod;
    printf(" x |   1   2   3   4   5   6   7   8   9  10\n");
    printf("--------------------------------------------\n");
    for (row = 1;row<=10;row++) {
        if (column == 0) {
            printf("%2d |",row);
        }
        for (column = 1;column <= 10;column++) {
                prod = column * row;
                printf("%4d",prod);
            }
        column = 0;
        printf("\n");
    }
    return 0;
}
