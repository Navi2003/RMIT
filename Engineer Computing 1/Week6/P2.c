#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    int i, spacecount, word;
    printf("Enter a sentence: ");
    scanf("%[^\n]s",s);
    spacecount=0;
    for(i=0;i<=strlen(s);i++){
        if(s[i]==' '){
            spacecount++;
        }
    }
    printf("There are %d words in this string.", word=(s[0]=='\0')?0:spacecount+1);
    return 0;
}