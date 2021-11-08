#include <stdio.h>
int main() {
    int input;
    printf("Enter an alphanumerical character: ");
    input = getchar();
    if (input>=48 && input<=57) {
        printf("It's a numerical character");
    } else if (input>=65 && input<=90){
        printf("It's a UPPERCASE alphabetical character");
    } else if (input>=97 && input<= 122){
        printf("It's a lowercase alphabetical character");
    } else {
        printf("It's not a alphanumerical character");
    }
    return 0;
}