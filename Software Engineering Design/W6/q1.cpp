#include <iostream>
#include <vector>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(){cout << "\nPerson construction moment.\n";};
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    ~Person(){cout << "\nPerson destruction moment.\n";}
};

class Student: public Person{
public:
    int studentID;

    Student(){cout << "\nStudent construction moment.\n";}
    Student(string name, int age, int studentID){
        this->name = name;
        this->age = age;
        this->studentID = studentID;
    }

    ~Student(){cout << "\nStudent destruction moment.\n";}
};

class Staff: public Person{
public:
    int staffID;

    Staff(){cout << "\nStaff construction moment.\n";};
    Staff(string name, int age, int staffID){
        this->name = name;
        this->age = age;
        this->staffID = staffID;
    }

    ~Staff(){cout << "\nStaff destruction moment.\n";};
};

class Tutor: public Student, public Staff{
public:
    Tutor(){cout << "\nTutor construction moment.\n";};
    Tutor(string name, int age, int studentID, int staffID){
        this->Student::name = name;
        this->Student::age = age;
        this->studentID = studentID;
        this->staffID = staffID;
    }

    void showInfo(){
        cout << "\nName: " << Student::name << "\n"
             << "Age: " << Student::age << "\n"
             << "Student ID: " << studentID << "\n"
             << "Staff ID: " << staffID << "\n";
    }

    void consultation(){
        cout << "\nConsultation moment.\n";
    }

    ~Tutor(){cout << "\nTutor destruction moment.\n";}
};

int main(){
    Tutor t1("lol", 12, 122, 1223),
          t2("lol2", 13, 1234, 456),
          t3("lol3", 45, 4532, 912);
    vector <Tutor> tvect{t1, t2, t3};

    tvect.erase(tvect.begin()+1);
    for (Tutor &tut : tvect){
        tut.showInfo();
    }

    return 0;
}