#include <stdio.h>
#define SIZE 50
int main(){
    char input[SIZE];
    printf("Enter a password: ");
    scanf("\n%[^\n]s",&input);
    for (int i=0;i<SIZE;i++){
        switch (input[i]){
        case 's':
        input[i]='$';
        break;
        case 'a':
        input[i]='@';
        break;
        case 'l':
        input[i]='1';
        break;
        case 'O':
        input[i]='0';
        break;
        }
    }
    printf("Result: %s",input);
    return 0;
}