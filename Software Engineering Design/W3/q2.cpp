#include <iostream>
#include <sstream>

class student {
private:   
    int score;
public:
    std::string name;

    student(){};
    student(std::string name_val, int score_val){
        name = name_val;
        score = score_val;
    }
    int get_score(){
        return score;
    }
    void set_new(student new_stu){
        this->score = new_stu.score;
        this->name = new_stu.name;
    }
    std::string showinfo(){
        std::stringstream sstr;
        sstr << "Name: " << name << ", Score: " << score;
        return sstr.str();
    }
};

int main(){
    student stu1("John", 50), stu2("John2", 502), stu3("John3", 503);
    student stu_arr[3] = {stu1, stu2, stu3};
    std::cout << stu1.showinfo() << std::endl;
    std::cout << stu2.showinfo() << std::endl;
    student max_score_stu = stu_arr[0];
    for (int i = 0; i < 3; i++){
        if(max_score_stu.get_score() < stu_arr[i].get_score()){
            max_score_stu.set_new(stu_arr[i]);
        }
    }
    std::cout << "Max score: " << max_score_stu.showinfo();
    return 0;
}
/*
#include <iostream>

class Student {
    private:
        std::string password = "";

    public:
        std::string name = "";
        int score;

        Student(std::string name_val, int score__val) { //constructor
            name = name_val;
            score = score__val;
        }
};

int main(int argc, char *argv[]){
    Student stu1("David James", 100), stu2("Peter Pan", 78);
    
    std::cout << "Name = " << stu1.name << ", Score = " << stu1.score << "\n";
    std::cout << "Name = " << stu2.name << ", Score = " << stu2.score << "\n";
    
    Student stu_arr[3] = { Student("David James", 100),
                           Student("Peter Pan", 78),
                           Student("John Smith", 83)
                        };

    std::cout << "Info of all students: \n";
    for (int i=0; i<3; i++){
        std::cout << "Name = " << stu_arr[i].score << "\n";
    }

    Student best_stu = stu_arr[0];
    for (int i = 1; i<3; i++){
        if (best_stu.score<stu_arr[i].score){
            best_stu.score = stu_arr[i].score;
            best_stu.name = stu_arr[i].name;
        }
    }
    std::cout << "Student with highest score: " << best_stu.name;
    return 0;
}
*/