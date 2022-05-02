#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
class Student{
private:
    std::string name;
    int scores[3];
public:
    Student(){};
    Student(std::string name_val, int scores_val[]){
        name = name_val;
        for (int i: {0, 1, 2}){
            scores[i] = scores_val[i];
        }
    }

    void inputData(){
        std::cout << "Enter student's name: ";
        char strtmp[100];
        do {
            std::cin.getline(strtmp, 100);
        } while (strlen(strtmp)==0);
        name = strtmp;
        std::cout << "Enter student's scores (3): ";
        std::cin >> scores[0] >> scores[1] >> scores[2];
    }

    void showInfo(){
        std::stringstream sstr;
        sstr << "Name: " << name << ", Scores: " << scores[0] << ", " << scores[1] << ", " << scores[2];
        std::cout << sstr.str();
    }
    
    friend std::istream &operator >>(std::istream &is, Student &stu);
    friend std::ostream &operator <<(std::ostream &os, Student &stu);

    bool operator >(Student stu){
        if (this->average_score() > stu.average_score()){
            return 1;
        } else return 0;
    }

    friend Student operator +(float n, Student stu);

    void setName(std::string name_val){
        name = name_val;
    }

    void setScores(std::string scores_val){
        std::stringstream sstr;
        sstr << scores_val;
        for (int i: {0, 1, 2}){
            sstr >> scores[i];
        }
    }

    float average_score (){
        return (this->scores[0]+this->scores[1]+this->scores[2])/3;
    }
};

std::istream &operator >>(std::istream &is, Student &stu){
    stu.inputData();
    return is;
}

std::ostream &operator <<(std::ostream &os, Student &stu){
    stu.showInfo();
    return os;
}

Student operator +(float n, Student stu){
    Student result = stu;
    for (int i = 0; i < 3; i++){
        result.scores[i] = stu.scores[i] + n;
    }
    return result;
}
int main(){
    Student stu1, stu2, stu3;
    std::cout << "stu1: \n"; 
    std::cin >> stu1;
    std::cout << "stu2: \n"; 
    std::cin >> stu2;
    if (stu1 > stu2){
        std::cout << "lol\n";
    }
    stu3 = 12 + stu1;
    std::cout << stu1 << "\n";
    std::cout << stu2 << "\n";
    std::cout << stu3 << "\n";

    Student *stu_list = new Student[10];
    std::fstream myfile;
    myfile.open("data.txt", std::ios::in);

    for (int i = 0; i < 10; i++){
        std::string temp;
        std::getline(myfile, temp, ',');
        stu_list[i].setName(temp);
        std::getline(myfile, temp);
        stu_list[i].setScores(temp);
    }
    myfile.close();
    Student max_avg_score = stu_list[0];
    for (int i = 0; i < 10; i++){
        if(max_avg_score.average_score() < stu_list[i].average_score()){
            max_avg_score = stu_list[i];
        }
    }
    std::cout << "Best student: " << max_avg_score;
    delete stu_list;
    return 0;
}