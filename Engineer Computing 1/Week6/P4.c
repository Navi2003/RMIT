#include <stdio.h>
#include <string.h>
int main(){
    char str[50];
    int i, length, check=0;
    printf("Enter a string: ");
    scanf("%s",str);
    length=strlen(str);
    for(i=0;i<length/2;i++){
        if(str[i]!=str[length-i-1]){
            check++;
            break;
        }
    }
    if(check){
        printf("Not a palindrome");
    } else{
        printf("Palindrome");
    }
    return 0;
}
