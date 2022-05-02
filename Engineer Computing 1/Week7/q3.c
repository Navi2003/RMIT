#include <stdio.h>
#include <string.h>
int main(){
    int num, len;
    char arr[20], arr1[20], c[20], d[20];
    char *p = arr, *p2 = arr1, *f = c, *r = d;
    printf("Enter a string: ");
    scanf("\n%[^\n]s",p);
    
    //a
    for (p;*p!='\0';p++){
        num++;
    }
    printf("Length: %d\n",num);

    //b
    p=arr;
    for (p;*p!='\0';p++){
        if(*p>='a' && *p<='z'){
            *p2=*p - 32;
        } else {
            *p2=*p;
        }
        p2++;
    }
    p2=arr1;
    printf("%s\n",p2);

    //c
    p=arr;
    printf("Find: ");
    scanf("\n%[^\n]s",f);
    printf("Replace: ");
    scanf("\n%[^\n]s",r);
    len = strlen(f);
    for(p;*p!='\0';p++){
        if(strncmp(p,f,len)==0){
            strncpy(p,r,len);
        }
    }
    p=arr;
    printf("%s",p);
    return 0;
}