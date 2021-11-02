#include <stdio.h>
int main(){
    //Declare variables for ASCII characters and character counter
    int value = 33, count = 0;
    
    //Loop for converting decimal to ASCII and printing out until the ASCII character '~'
    while (value<127){
    putchar(value);
    printf(" ");
    value++;
    count++;
        //Create new line every 15 characters
        if (count%15==0){
            printf("\n");
        }
    }
    return 0;
}