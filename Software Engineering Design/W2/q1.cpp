#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cerr << "Incorrect number of arguments";
        return -1;
    }
    if (argv[1][0] == '0' && (argv[1][1] == 'x' || argv[1][1] == 'X')){
        if (strlen(argv[1]) != 4){
            std::cerr << "Not hexadecimal";
            return -2;
        }
        if (argv[1][2] < 'A' || argv[1][2] > 'Z' || argv[1][3] < 'A' || argv[1][3] > 'Z'){
            std::cerr << "Hexadecimal digits must be uppercase";
            return -3;
        }
    } else {
        std::cerr << "Wrong prefix";
        return -4;
    }
    std::cout << "Valid hexadecimal: " << argv[1];
    return 0;
}






































/*
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2){
        std::cerr << "Incorrect number of arguments";
        return -1;
    }
    if (strncmp(argv[1], "0x", 2) == 0 || strncmp(argv[1], "0X", 2) == 0){
        if (strlen(argv[1]) < 3){
            std::cerr << "Not hexa digit";
            return -2;
        }

        for (int i = 2; argv[1][i] != '\0'; i++) {
            if ((argv[1][i] >= '0' && argv[1][i] <= '9') || (argv[1][i] >= 'A' && argv[1][i] <= 'F')){
                continue;
            } else {
                std::cerr << "At least 1 digit not valid";
                return -3;
            }
        }

        std::cout << "Valid hexadecimal number: " << argv[1];
    } else {
        std::cerr << "Wrong prefix (0x, 0X)";
        return -4;
    }
    return 0;
}
*/