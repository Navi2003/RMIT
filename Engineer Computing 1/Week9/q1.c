#include <stdio.h>

void myfunc(int *num) {
        *num = 20;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    //q1a
    int x = 10;
    printf("x bfore function call: %d \n", x);
    myfunc(&x);
    printf("x after function call: %d \n", x);

    //q1b
    int n1 = 50, n2 = 60;
    printf("Values before swapping: n1 = %d, n2 = %d \n", n1, n2);
    swap(&n1, &n2);
    printf("Values after swapping: n1 = %d, n2 = %d \n", n1, n2);
}