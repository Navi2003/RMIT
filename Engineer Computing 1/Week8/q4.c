#include <stdio.h>

void search(char arr[], char find[]){
    for (int i=0;arr[i]!='\0';i++){
        int check=0;
        for (int j=0;find[j]!='\0';j++){
            if(find[j]!=arr[i+j]){
                check++;
                break;
            }
        }
        if (check==0){
            printf("Yes");
            break;
        } else if (arr[i+1]=='\0'){
            printf("No");
            break;
        }
    }
}

int main(){
    char array[50],find[20];
    printf("Enter text: ");
    scanf("%[^\n]s",&array);
    printf("Search: ");
    scanf("\n%[^\n]s",&find);
    search(array, find);
    return 0;
}