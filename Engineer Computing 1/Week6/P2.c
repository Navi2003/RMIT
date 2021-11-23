#include <stdio.h>
int main(){
    char s[100];
    int i, spacecount;
    printf("Enter a sentence: ");
    scanf("%[^\n]s",s);
    spacecount=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            spacecount++;
        }
    }
    printf("There are %d words in this string.", spacecount+1);
    return 0;
}