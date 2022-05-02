#include <iostream>
#include <cstring>

bool check_float(char arr[]){
    int dot_count = 0;
    if((arr[0] > '9' || arr[0] < '0') && arr[0]!='-'){
        return 0;
    }
    for (int i = 1; i < strlen(arr); i++){
        if((arr[i] > '0' && arr[i] < '9') || arr[i] == '.'){
            if(arr[i] == '.'){
                dot_count++;
            }
        } else {
            return 0;
        }
    }
    if(dot_count > 1){
        return 0;
    } else return 1;
}

int main(int argc, char* argv[]){
    if(argc != 11){
        std::cerr << "Invalid number of arguments";
        return -1;
    }
    for(int i = 1; i < 11; i++){
        if(check_float(argv[i]) == 0){
            std::cerr << "At least 1 invalid float";
            return -2;
        }
    }
    float str[10], *p;
    p = str;
    for(int i = 1; i < 11; i++){
        *(p+i-1) = atof(argv[i]);
        std::cout << *(p+i-1) << " ";
    }

    return 0;
}





































/*
#include <iostream>
#define NUM_FLOAT 10

int check_float (char str[]){
    if ((str[0] < '0' || str[0] > '9') && str[0] != '+' && str[0] != '-'){
        return 0;
    }

    for (int i = 1; str[i] != '\0'; i++){
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.'){
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]){
    if (argc != NUM_FLOAT + 1){
        std::cerr << "Invalid number of arguments.";
        return -1;
    }

    for (int i = 1; i < argc; i++){
        if(check_float(argv[i]) == 0){
            std::cerr << "At least 1 invalid float";
            return -2;
        }
    }

    std::cout << "Valid floats: ";
    float arr[NUM_FLOAT], *p;
    p = arr;
    for (int i = 1; i < argc; i++){
        *(p + (i - 1)) = atof(argv[i]);
        std::cout << *(p + (i - 1)) << " ";
    }
    return 0;
}
*/