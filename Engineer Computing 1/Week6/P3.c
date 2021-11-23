#include <stdio.h>
#include <string.h>
int main(){
    char name[5][50], firstname[5][20],temp[50];
    int i, j, space, switchcount;
    for(i=0;i<5;i++){
        printf("Enter full name %d: ",i+1);
        scanf("\n%[^\n]s",name[i]);
    }
    for(i=0;i<5;i++){
        space=0;
        for(j=0;name[i][j]!=' ';j++){
            space++;
        }
        strncpy(firstname[i], name[i], space);
        firstname[i][space]='\0';
    }
    printf("First names:");
    for(i=0;i<5;i++){
        printf(" %s",firstname[i]);
    }
    printf("\n");
    
    do{
        switchcount=0;
        for(i=0;i<4;i++){
            if(strcmp(name[i],name[i+1])>0){
                strcpy(temp,name[i]);
                strcpy(name[i],name[i+1]);
                strcpy(name[i+1],temp);
                switchcount++;
            }
        }
    } while(switchcount!=0);
    printf("Sorted names: \n");
    for(i=0;i<5;i++){
        printf("%s",name[i]);
        printf("\n");
    }
    return 0;
}