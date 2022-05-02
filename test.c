#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
void printnumarr(int numarr[], int size){
    if (size == 0)
        return;
    printf("%d ", *numarr); 
    printnumarr(numarr+1, size-1);
}


int main (){
    typedef enum {PASS, FAIL, ABSENT} status;
status stud1, stud2, stud3;
stud1 = PASS;
stud2 = ABSENT;
stud3 = FAIL;
printf("%d, %d, %d\n", stud1, stud2, stud3);
return 0;
}