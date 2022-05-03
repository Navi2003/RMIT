#include <iostream>
#include <vector>

using namespace std;

class Book{
private:
    string title;
    int availableCopies;
    vector <string> namesOfBorrowers;
public:
    Book(){}
    Book(string title, int availableCopies, vector <string> nameOfBorrowers){
        this->title = title;
        this->availableCopies = availableCopies;
        this->namesOfBorrowers = nameOfBorrowers;
    }

    friend class User;
    friend class SuperUser;

    void showInfo(){
        cout << "Title: " << title
             << "Stock: " << availableCopies;
    }

};

class User{
private:
    string name;
    vector <Book*> borrowedBooks;
public:
    User(){}
    User(string name, vector <Book*> borrowedBooks){
        this->name = name;
        this->borrowedBooks = borrowedBooks;
    }

    virtual bool doBorrow(Book &abook){
        if(abook.availableCopies == 0){
            return 0;
        }
        borrowedBooks.push_back(&abook);
        abook.namesOfBorrowers.push_back(name);
        abook.availableCopies--;
        return 1;
    }

    void doReturn(Book &abook){
        for (int i = 0; i < borrowedBooks.size(); i++){
            if (borrowedBooks[i] == &abook){
                borrowedBooks.erase(borrowedBooks.begin() + i);
            }
        }
        abook.availableCopies++;
    }

    void showInfo(){
        cout << "Name: " << name
             << "Borrowed books: ";
        for (auto book : borrowedBooks){
            cout << book->title << "   ";
        }
    }

    friend class SuperUser;
};

class SuperUser: public User{
public:
    bool doBorrow(Book &abook1, Book &abook2){
        if (abook1.availableCopies == 0 || abook2.availableCopies == 0){
            return 0;
        }
        borrowedBooks.push_back(&abook1);
        borrowedBooks.push_back(&abook2);
        abook1.namesOfBorrowers.push_back(name);
        abook2.namesOfBorrowers.push_back(name);
        abook1.availableCopies--;
        abook2.availableCopies--;
    }
};

int main(){
    Book b1("b1", 5, vector <string>{}),
         b2("b2", 6, vector <string>{}),
         b3("b3", 7, vector <string>{});
    Book *bList = new Book[3]{b1, b2, b3};

    User u1("u1",vector<Book*>{&b1, &b2}),
         u2("u2",vector<Book*>{&b2, &b3});

    

    return 0;
}