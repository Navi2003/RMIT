
#include <iostream>
#include <sstream>
#include <cstring>
#define STRSIZE 100

class Book {
    public:
    std::string *name;
    int price;

    void allocate_memory_name(){
        name = new (std::nothrow) std::string;
        if (this->name == NULL) {
            std::cerr << "Fail to allocate memory \n";
        }
    }

    //Constructor
    Book(){
        allocate_memory_name();
    }
    Book(std::string name_val, int price_val){
        allocate_memory_name();
        this->price = price_val;
    }

    //Function to return string of info
    std::string toString() {
        std::stringstream sstr;
        sstr << "name = " << name << ", price = " << price;
        return sstr.str();
    }

    

    //destructor
    ~Book(){
        delete name;
    }

};

int main(){
    //qa
    Book *book1 = new (std::nothrow) Book("Harry Potter", 100);

    if (book1 == NULL) {
        std::cerr << "Fail to allocate memory \n";
        return -1;
    }

    std::cout << "Info of book1: " << book1->toString();

    //free up memory
    delete book1;
    
    //qb
    int size;
    std::cout << "\nEnter number of books: ";
    std::cin >> size;

    Book *book_arr = new (std::nothrow) Book[size];
    if (book_arr == NULL) {
        std::cerr << "Fail to allocate memory \n";
        return -2;
    }

    char str_temp[STRSIZE];

    std::cout << "Input information for the books: \n";
    for (int i = 0; i < size; i++){
        std::cout << "Book " << i + 1 << "'s name: ";

        do {
            std::cin.getline(str_temp, sizeof(str_temp));
        } while (strlen(str_temp) == 0);

        *book_arr[i].name = str_temp;
        std::cout <<">price: ";
        std::cin >> book_arr[i].price;
    }

    for (int i = 0; i < size; i++){
        std::cout << book_arr[i].toString() << "\n";
    }


    Book *most_exp = &book_arr[0];
    for (int i = 0; i < size; i++){
        if (most_exp->price < book_arr[i].price){
            most_exp = &book_arr[i];
        }
    }
    std::cout << most_exp->toString();

    //qc
    return 0;
}
