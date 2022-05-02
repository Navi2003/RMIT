#include <stdio.h>

int main(){
    char arr[] = {10, 20, 30, 40, 50, 60};
    char *p = arr, *add[5];
    int i;
    for(i=0;i<6;i++){
        add[i] = &arr[i];
        printf("%p\n",add[i]);
    }
    return 0;
}

//a. Change int to char.
//b. Answer is d., e.
//c. 2. Using normal index and using pointer. 
//d. int = 4 bytes, char = 1 byte.