#include <iostream>
#include <cstring>
#define STRSIZE 100

union Student{
    char firstName[STRSIZE];
    char fullName[STRSIZE];
};

int main(){
    Student stu_arr[3];
    
    std::cout << "Input full names for students: \n";
    for (int i = 0; i<3; i++){
        std::cout << "Student "<< i + 1 << ": ";
        //input string w space
        do {
            std::cin.getline(stu_arr[i].fullName, sizeof(stu_arr[i].fullName));
        } while (strlen(stu_arr[i].fullName) == 0);
    }

    //qb
    //range based loop
    int count = 0;
    for (Student stu: stu_arr){
        std::cout << "Student " << ++count << "'s full name: " << stu.fullName << "\n";
    }

    //change 1st name (access by reference)
    for (Student &stu: stu_arr){
        strcpy(stu.firstName, "NA");
    }
    std::cout << "First names after being changed: \n";
    count = 0;
    for (Student stu: stu_arr) {
        std::cout << "Student " << ++count << "'s full name: " << stu.fullName << "\n";
    }

    
    return 0;
}