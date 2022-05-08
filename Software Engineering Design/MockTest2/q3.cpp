#include <iostream>
#include <vector>

using namespace std;

class Product{
private:
    string name;
    int price;
public:
    Product(){};
    Product(string name, int price){
        this->name = name;
        this->price = price;
    }
    friend class Shop;
    friend class Acc;
    friend class GoldAcc;
};

class Shop{
private:
    string name;
    vector <Product*> productList;
public:
    Shop(){};
    Shop(string name, vector <Product*> productList){
        this->name = name;
        this->productList = productList;
    }

};

class Acc{
private:
    string name;
    double bill;
    vector <Product*> boughtProduct;
public:
    Acc(){};
    Acc(string name, double bill, vector <Product*> boughtProduct){
        this->name = name;
        this->bill = bill;
        this->boughtProduct = boughtProduct;
    }

    virtual void buyProduct(Product p){
        boughtProduct.push_back(&p);
        bill += p.price;
    }

    virtual bool doReturn(){
        cout << "\nWhich product do you want to return?\n";
        int i = 1, choice; 
        for (Product *prod: boughtProduct){
            cout << i << ". " << prod->name << "\n";
            i++;
        }
        cout << "Choose: ";
        cin >> choice;
        Product *returnProd = boughtProduct[choice - 1];
        if(choice - 1 < boughtProduct.size()){
            bill -= (returnProd->price);
            bill += (returnProd->price*1/10);
            boughtProduct.erase(boughtProduct.begin() + choice - 1);
            cout << "\nReturn success\n";
            return 1;
        } else {
            cout << "\nError. Not a choice\n";
            return 0;
        }
    }

    void showCart(){
        cout << "\n" << name << "'s Cart: \n";
        for (Product *prod: boughtProduct){
            cout << prod->name << ": $" <<  prod->price << "\n";
        }
        cout << "Total price: $" << bill << "\n";
    }
    
    friend class GoldAcc;
};

class GoldAcc : public Acc{
private:
    double discRate;
public:
    GoldAcc(){};
    GoldAcc(string name, double bill, double discRate, vector <Product*> boughtProduct){
        this->name = name;
        this->bill = bill;
        this->discRate = discRate;
        this->boughtProduct = boughtProduct;
    }

    void buyProduct(Product p){
        boughtProduct.push_back(&p);
        bill+=(p.price-p.price*discRate/100);
    }

    bool doReturn(){
        cout << "\nWhich product do you want to return?\n";
        int i = 1, choice; 
        for (Product *prod: boughtProduct){
            cout << i << ". " << prod->name << "\n";
            i++;
        }
        cout << "Choose: ";
        cin >> choice;
        Product *returnProd = boughtProduct[choice - 1];
        if(choice - 1 < boughtProduct.size()){
            bill -= (returnProd->price-returnProd->price*15/100);
            bill += (returnProd->price*5/100);
            boughtProduct.erase(boughtProduct.begin() + choice - 1);
            cout << "\nReturn success\n";
            return 1;
        } else {
            cout << "\nError. Not a choice\n";
            return 0;
        }
    }
};


int main(){
    Product p1("Milk1", 100), p2("milk2", 200);
    Shop s1("Shop1", {&p1, &p2});
    Acc acc1("Dude1", 0, {});
    GoldAcc goldacc1("GoldDude1", 0, 15, {});

    acc1.buyProduct(p1);
    acc1.buyProduct(p2);
    acc1.showCart();

    goldacc1.buyProduct(p1);
    goldacc1.buyProduct(p2);
    goldacc1.showCart();

    acc1.doReturn();
    acc1.showCart();

    goldacc1.doReturn();
    goldacc1.showCart();

    return 0;
}