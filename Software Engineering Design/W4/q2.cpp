#include <iostream>
#include <cstring>
#include <cctype>

int main(){
    std::string str1, str2;
    char tmp[100];
    std::cout << "Enter string 1: ";
    std::cin.getline(tmp, 100);
    str1 = tmp;

    std::cout << "Enter string 2: ";
    std::cin.getline(tmp, 100);
    str2 = tmp;

    //a
    for (int i = 0; i < (str1.length()/2); i++){
        char ch = str1[i];
        str1[i] = str1[str1.length() - i -1];
        str1[str1.length() - i - 1] = ch;
    }
    std::cout << str1 << "\n";

    //b
    for (int i = 0; i < str2.length(); i++){
        if (islower(str2[i])){
            str2[i] -= 32;
            continue;
        }
        if (isupper(str2[i])){
            str2[i] += 32;
        }
    }
    std::cout << str2;
    return 0;
}