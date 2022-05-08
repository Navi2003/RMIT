/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 2
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: gcc 8.1.0
  Created  date: 6/5/2022
  Acknowledgement: StackOverflow, lecture slides, previous tutorials
*/

#include <iostream>
#include <vector>

using namespace std;

class Product;
class Shop;
class Customer;

//Product class
class Product{
//Declare attributes
private:
    string name, ID;
    double price;
public:
    //Constructors
    Product(){};
    Product(string name, string ID, double price){
        this->name = name;
        this->price = price;
        this->ID = ID;
    }

    friend class Shop;
    friend class Customer;
};


class Customer{
//Declare attributes
private:
    string name, ID;
    vector <Product> currentBill;
    double totalSpent = 0;
public:
    //Constructors
    Customer(){};
    Customer(string name, string ID){
        this->name = name;
        this->ID = ID;
    }

    //Function to add products to cart
    void addToCart(Product prod){
        currentBill.push_back(prod);
        cout << "Successfully added " << prod.name << " to cart\n";
    }
    
    //Function to show customer info
    void showInfo(){
        cout << "\nName: " << name << "\n"
             << "ID: " << ID << "\n"
             << "Current Bill: ";
        for (Product prod : currentBill){
            cout << prod.name << "\n";
        }
        if (currentBill.empty()){
            cout << "\n";
        }
        cout << "Total spent: $" << totalSpent << "\n";
    }
    friend class Shop;
    friend void makePurchase(Shop *s, Customer *c);
};


class Shop{
//Declare attributes
private:
    string name;
    vector <Product> productList;
    double totalRev = 0;
public:
    //Constructors
    Shop(){};
    Shop(string name, vector <Product> productList){
        this->name = name;
        this->productList = productList;
    }

    //Function to calculate bill
    double calculateBill(Customer *c){
        cout << "\n\nCalculate bill for " << c->name << ":";
        double totalBill;
        cout << "\nItems in cart: \n";
        for (Product prod: c->currentBill){
            cout << prod.name << "\n";
            totalBill += prod.price;
        }
        cout <<  "Total bill: $" << totalBill << "\n";
        totalRev += totalBill;
        c->totalSpent += totalBill;
        c->currentBill.clear();
        return totalBill;
    };

    //Function to show shop info
    void showInfo(){
        cout << "\nShop name: " << name << "\n"
             << "Product list: \n";
        int i = 1;
        for (Product prod : productList){
            cout << i << ". " << prod.name << "  $" << prod.price << "\n";
            i++;
        }
        cout << "Total revenue: $" << totalRev << "\n";
    }

    friend class Product;
    friend class Customer;
    friend void makePurchase(Shop *s, Customer *c);
};

//Function to make purchase

void makePurchase (Shop *s, Customer *c){
    int choice;
    s->showInfo();
    cout << "Enter the product you want to buy: ";
    cin >> choice;
    c->addToCart(s->productList[choice-1]);
}


int main(){
    Product p1("Milk", "1", 10), p2("Sugar", "2", 15);
    Shop s1("Shopee", {p1, p2});
    Customer c1("John", "c1");
    string choice;
    
    makePurchase(&s1, &c1);
    //Buying products and show cart
    c1.showInfo();
    
    //Calculate bill and pay
    s1.calculateBill(&c1);

    //Show info to check spent and revenue
    cout << "\n";
    c1.showInfo();
    s1.showInfo();
    return 0;
}