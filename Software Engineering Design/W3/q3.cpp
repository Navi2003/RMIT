#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

class student {
private:   
    int score;
    std::string password;
public:
    std::string name;

    student(){};
    student(std::string name_val, int score_val, std::string pwd_val){
        name = name_val;
        score = score_val;
        password = pwd_val;
    }
    int get_score(){
        return score;
    }
    std::string get_pwd(){
        return password;
    }
    void set_new(student new_stu){
        this->score = new_stu.score;
        this->name = new_stu.name;
    }
    void change_pwd(std::string new_pwd){
        this->password = new_pwd;
    }
    std::string showinfo(){
        std::stringstream sstr;
        sstr << "Name: " << name << ", Score: " << score;
        return sstr.str();
    }
};
int main(){
    student stu1("John", 50, "Fat");
    std::string pwd, prev_pwd;
    std::fstream myfile;
    if (stu1.get_pwd().length() == 0){
        std::cout << "No password. Enter a password: ";
        std::cin >> pwd;
        stu1.change_pwd(pwd);
        myfile.open(stu1.name + ".dat", std::ios::out);
        myfile << stu1.get_pwd();
        myfile.close();
    } else {
        std::cout << "Enter password: ";
        std::cin >> pwd;
        if (pwd == stu1.get_pwd()){
            std::cout << "Enter new password: ";
            std::cin >> pwd;
            stu1.change_pwd(pwd);
            myfile.open(stu1.name + ".dat", std::ios::out);
            myfile << stu1.get_pwd();
            myfile.close();
        } else {
            std::cout << "Incorrect password";
        }
    }
    return 0;
}












































/*

#include <iostream>
#include <fstream>

class Student {
    private:
        std::string password = "";

    public:
        std::string name = "";
        int score;

        Student(std::string name_val, int score__val, std::string password_val) { //constructor
            name = name_val;
            score = score__val;
            password = password_val;
        }
};

void change_pwd(){
    std::string prev_pwd, new_pwd;
    std::fstream myfile;
    myfile.open( + ".dat", std::ios::in);
    myfile.close();
    std::getline(myfile, prev_pwd);

    if (prev_pwd.length() == 0){
        std::cout << "no existing password";
    } else {
        std::cout << "existing password";
    }

}
*/