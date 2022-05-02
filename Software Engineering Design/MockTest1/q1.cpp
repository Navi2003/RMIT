#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
int doubleVal(int num){
    return num*2;
}

double doubleVal(double num){
    return num*2; 
}

std::string doubleVal(char num[]){
    int numint;
    std::stringstream sstr, sstr2;
    sstr << std::hex << num;
    sstr >> numint;
    sstr2 << std::hex << numint*2; 
    return sstr2.str();
}

int type_check(char num[]){
    int type;
    for (int i = 0; i < strlen(num); i++){
        if (num[i] == '.'){
            return 1;
        }
    }

    if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X')){
        return 2;
    }
    return 0;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cerr << "Incorrect number of arguments";
        return -1;
    }
    if (type_check(argv[1]) == 0){
        std::cout << doubleVal(atoi(argv[1]));
    } else if (type_check(argv[1]) == 1){
        std::cout << std::fixed << std::setprecision(2) << doubleVal(atof(argv[1]));
    } else {
        std::cout << doubleVal(argv[1]);
    }
    
    return 0;
}