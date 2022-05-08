#include <iostream>

using namespace std;

class Acc{
public:
    string name;
    double bill;

    Acc(){};
    Acc(string name, double bill){
        this->name = name;
        this->bill = bill;
    }

    virtual void buyProduct(int price){
        bill += price;
    }

};

class GoldAcc : public Acc{
public:
    double discRate;

    GoldAcc(){};
    GoldAcc(string name, double bill, double discRate){
        this->name = name;
        this->bill = bill;
        this->discRate = discRate;
    }

    void buyProduct(int price){
        bill+=(price-price*discRate/100);
    }

};

int main(){
    Acc acc1("Dude1", 0), acc2("Dude2", 0);
    GoldAcc goldacc1("GoldDude1", 0, 15);

    acc1.buyProduct(100);
    cout << acc1.bill << "\n";
    goldacc1.buyProduct(100);
    cout <<goldacc1.bill;

    return 0;
}