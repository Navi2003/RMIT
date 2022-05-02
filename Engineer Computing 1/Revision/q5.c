#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STRSIZE 100
int main(){
    char str[50];
    printf("Enter a string: ");
    scanf("%[^\n]s",&str);
    int max_length = 0;
    char max_word[STRSIZE];
    for (int i = 0; str[i] != '\0'; i++) {
        //Extract a word
        char word[STRSIZE];
        int j;
        for (j = 0; !isspace(str[i]) && str[i] != '\0'; j++, i++) {
            word[j] = str[i];
        }
        word[j] = '\0'; //put '\0' at the end

        //Update if found longer word
        if (strlen(word) > max_length) {
            max_length = strlen(word);
            strcpy(max_word, word);
        }
    }

    printf("Max words: %s",max_word);
    return 0;
}