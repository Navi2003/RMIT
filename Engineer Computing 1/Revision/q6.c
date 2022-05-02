#include <stdio.h>
#include <math.h>
#include <string.h>
int atoi(char arr[]){
    int out=0;
    for (int i=0;arr[i]!='\0';i++){
        if (arr[i]<'0' || arr[i]>'9'){
            printf("Can't be converted");
            return 0;
        }
    }
    int size = strlen(arr);
    for (int i=0;arr[i]!='\0';i++){
        out+=(arr[i]-'0')*pow(10,size-1-i);
    }
    return out;
}

int main(){
    char num[]= "1342123";
    printf("Conversion: %d",atoi(num));
    return 0;
}

/*From teacher
#include <stdio.h>
#include <ctype.h>
#define STRSIZE 50

int atoi(const char *str){
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++){
        //Get value of each digit and put in num
        if ( isdigit(str[i]) ){
            num = num*10 + (str[i] - '0');
        } else {
            return 0; //found invalid non-digit character
        }
    } 
    return num;
}


int main() {
    char str[STRSIZE];
    printf("Input a string of only digits: ");
    scanf("%s", str); 

    printf("Converted value: %d\n", atoi(str));
    return 0;
}
*/