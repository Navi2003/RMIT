#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]){
    int num;
    float num2;
    char str[50];
    std::cout << std::showpos << 200 << " ";
    std::cout << std::noshowpos << 200 << "\n\n";
    std::cout << std::left << std::setw(5) << 10 << "\n";
    std::cout << std::left << std::setw(5) << 200 << "\n";
    std::cin >> std::hex >> num;
    std::cout << num << "\n";
    num = 100;
    std::cout << std::hex << num << "\n";
    num2 = 1.234;
    std::cout.fill('0');
    std::cout << std::setw(9) << num2 << "\n";
    std::cout << std::setprecision(2) << std::fixed << num2 << "\n";
    std::cin >> str;
    for (int i = 0; str[i]!= '\0'; i++){
        std::cout << str[i] << " ";
    }
    return 0;
}