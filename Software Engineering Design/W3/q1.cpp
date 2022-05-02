#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
    int choice;
    char pwd[50];

    std::cout << "Password management program: \n"
              << "1. Save your password\n"
              << "2. Read your password\n"
              << "Your choice: ";
    std::cin >> choice;
    std::fstream myfile;
    if(!myfile){
        std::cerr << "Failed to open file.";
        return -1;
    }
    if (choice == 1){
        myfile.open("pwd.dat", std::ios::out);
        std::cout << "Save your password: ";
        std::cin >> pwd;
        myfile << pwd << std::endl;
    }
    if (choice == 2){
        myfile.open("pwd.dat", std::ios::in);
        myfile >> pwd;
        std::cout << pwd;
    }
    myfile.close();
    return 0;
}