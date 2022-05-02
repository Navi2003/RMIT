#include <iostream>

class Cat {
public:
    std::string name;
    int age;

    Cat(){};
    Cat(std::string name_val, int age_val){
        name = name_val;
        age = age_val;
    }
};

class person {
public:
    Cat cat;
    std::string name;

    person(){};
    person(Cat cat_val, std::string name_val){
        cat = cat_val;
        name = name_val;
    }
};

int main(){
    Cat cat1("kuro", 5), cat2("ao", 6), cat3("aka", 7);
    person p1(cat1, "John"), p2(cat2, "Sam"), p3(cat3, "Alex");
    person person_arr[3] = {p1, p2, p3};
    person max_cat_age = person_arr[0];
    for (int i = 0; i < 3; i++){
        if(max_cat_age.cat.age < person_arr[i].cat.age){
            max_cat_age = person_arr[i];
        }
    }
    std::cout << "Name: " << max_cat_age.name; 
    return 0;
}