#include <iostream>
#include <sstream>
int main(){
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;  
    for (num; num>0; num/=10){
        std::cout << num%10;
    }
    return 0;
}





/*
#include <iostream>

int main(){
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    for (num; num > 0; num/=10){
        std::cout << num % 10;
    }
    return 0;
}
*/