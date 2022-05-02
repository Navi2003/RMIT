
#include <iostream>

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cerr << "Invalid number of arguments";
        return -1;
    }
    char const *roman_sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int roman_val[]= {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int num = atoi(argv[1]);
    if(num == 0){
        std::cerr << "No zero in roman numeral";
        return -2;
    }
    for (int i = 12; i >= 0; i--){
        while (num >= roman_val[i]){
            std::cout << roman_sym[i];
            num = num - roman_val[i];
        }
    }
    return 0;
}

































/*

#include <iostream>

int main(int argc, char *argv[]){
    int num;
    if (argc > 2){
        std::cerr << "Incorrect number of arguments";
        return -1;
    } else if (argc == 2){
        num = atoi(argv[1]);
    } else {
        std::cout << "Input an integer: ";
        std::cin >> num;
    }

    if(num == 0){
        std::cerr << "No zero in roman numerals";
        return -2;
    }

    int dec_vals[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    const char *roman_symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    std::cout << "Converted to roman: ";
    for (int i = 12; i >= 0; i--){
        while (num >= dec_vals[i]){
            std::cout << roman_symbols[i];
            num = num - dec_vals[i];
        }
    }

    return 0;
}
*/