#include <stdio.h>
#include <string.h>
int main(){
    char source[10], dest[20];
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", 
"October", "November", "December"};
    printf("Enter dd/mm/yyyy: ");
    scanf("%s",&source);
    strncpy(dest,source,2);
    dest[2]=' ';
    printf("%s\n",dest);
    int month = (source[3]-'0')*10 + source[4]-'0';
    for (int i=1;i<=12;i++){
        if (month==i){
            strcat(dest,months[i-1]);
            break;
        }
    }
    strcat(dest," ");
    strcat(dest,source+6);
    dest[strlen(dest)-1]='\0';
    printf("%s",dest);
    return 0;
}