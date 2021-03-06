#include <iostream>
#include <vector>

using namespace std;

class Product;
class Shop;
class Customer;

//Product class
class Product{
//Declare attributes

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

    //Function to check out
    void checkOutCurrentCart(){
        for(Product prod: currentBill){
            totalSpent += prod.price;
        }
        currentBill.clear();
    }
    
    void showInfo(){
        cout << "Name: " << name << "\n"
             << "ID: " << ID << "\n"
             << "Current Bill: ";
        for (Product prod : currentBill){
            cout << prod.name << "  ";
        }
        cout << "\nTotal spent: $" << totalSpent;
    }
    friend class Shop;
};


class Shop{
//Declare attributes
private:
    string name;
    vector <Product> productList;
    double totalRev;
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
        c->checkOutCurrentCart();
        return totalBill;
    };

    friend class Product;
    friend class Customer;
};


int main(){
    Product p1("Milk", "1", 10), p2("Sugar", "2", 15);
    Shop s1("Shopee", {p1, p2});
    Customer c1("John", "c1");


    c1.addToCart(p1);
    c1.addToCart(p2);
    c1.showInfo();
    
    s1.calculateBill(&c1);

    cout << "\n";
    c1.showInfo();
    return 0;
}