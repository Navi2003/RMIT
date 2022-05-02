#include <iostream>
#include <cstring>

bool check_int(char arr[]){
    if((arr[0] > '9' || arr[0] < '0') && arr[0] != '-'){
        return 0;
    }
    for (int i = 1; i < strlen(arr); i++){
        if(arr[i] > '9' || arr[i] < '0'){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]){
    if (argc != 6){
        std::cerr << "Incorrect number of arguments";
        return -1;
    }
    for (int i = 1; i < 6; i++){
        if(check_int(argv[i]) == 0){
            std::cerr << "At least 1 invalid";
            return -2;
        }
    }
    int *p, arr[5];
    p = arr;
    for (int i = 1; i < 6; i++){
        *(p+i-1) = atoi(argv[i]);
        std::cout << *(p+i-1) << " ";
    }
    return 0;
}





































/*
#include <iostream>
#define NUM_INT 5

bool check_int(char str[]){
    if ((str[0] < '0' || str[0] >'9') && str[0] != '+' && str[0] != '-'){
        return 0;
    }

    for (int i=1; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9'){
            return 0;
        }
    }

    return 1;
}


int main(int argc, char *argv[]){
    if (argc != NUM_INT + 1){
        std::cerr << "Invalid number of arguments";
        return -1;
    }

    for (int i=1; i < argc; i++){
        if (check_int(argv[i]) == 0){
            std::cerr << "At least one argument is not valid integer";
            return -2;
        }
    }
    int arr[NUM_INT], *p;
    p = arr;
    std::cout << "Valid integers: ";
    for (int i=1; i < argc; i++){
        *(p + (i - 1)) = atoi(argv[i]);
        std::cout << *(p + (i - 1)) << " ";
    }
    return 0;
}
*/