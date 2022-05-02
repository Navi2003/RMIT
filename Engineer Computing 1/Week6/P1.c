#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[100], s1[100], temp;
    int i, count, upcount, lowcount, dgcount, punccount, totalletter;
    printf("Enter a string: ");
    scanf("%[^\n]s",s);
    count=0;
    for (i=0;s[i]!='\0';i++){
        count++;
    }
    printf("String length: %d\n",count);
    upcount=0;
    lowcount=0;
    dgcount=0;
    punccount=0;
    for (i=0;s[i]!='\0';i++){
        if(s[i]>='A' && s[i]<='Z'){
            upcount++;
        } else if(s[i]>='a' && s[i]<='z'){
            lowcount++;
            } else if(s[i]>='0' && s[i]<='9'){
                dgcount++;
                } else if(s[i]>='!' && s[i]<='~'){
                    punccount++;
                    }
    }
    totalletter=upcount+lowcount;
    printf("Number of uppercase characters: %d\n", upcount);
    printf("Number of lowercase characters: %d\n", lowcount);
    printf("Number of digits: %d\n", dgcount);
    printf("Number of punctuations: %d\n", punccount);
    printf("Total letters: %d\n", totalletter);
    
    strcpy(s1,s);
    for(i=0;i<=100;i++){
        s1[i]=(islower(s[i]))? toupper(s1[i]): tolower(s1[i]);
    }
    printf("Inverse case string: %s\n",s1);
    
    for(i=0;i<=(count-1)/2;i++){
        temp=s[i];
        s[i]=s[count-1-i];
        s[count-1-i]=temp;
    }
    printf("Reverse string: %s \n",s);
    return 0;
}