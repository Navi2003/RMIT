/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 2
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: gcc 8.1.0
  Created  date: 6/5/2022
  Acknowledgement: lecture slides
*/

#include <iostream>

using namespace std;


class RegularAcc {
//Declare attributes
private:
    string name;
    double balance;
public:
    //Constructors
    RegularAcc(){};
    RegularAcc(string name, double balance){
        this->name = name;
        this->balance = balance;
    }

    //Function to pay money
    virtual bool pay(double amount){
        if(amount <= balance){
            balance -= amount;
            cout << "\nPaid $" << amount << " successfully\n";
            return 1;
        } else return 0;
    }

    //Function to show info
    virtual void showInfo(){
        cout << "\nName: " << name << "\n"
             << "Balance: $" << balance << "\n";
    }

    friend class GoldAcc;
};

class GoldAcc: public RegularAcc{
//Declare attributes
private:
    double bonusCoin;

public:
    //Constructors
    GoldAcc(){};
    GoldAcc(string name, double balance, double bonusCoin){
        this->name = name;
        this->balance = balance;
        this->bonusCoin = bonusCoin;
    }

    //Function to pay money for gold account
    bool pay(double amount){
        if(amount <= balance){
            balance -= amount;
            bonusCoin += amount*0.05;
            cout << "\nPaid $" << amount << " successfully\n"
                 << "$" << amount*0.05 << " added to bonus coin\n";
            return 1;
        } else return 0;
    }

    //Function to show info for gold account
    void showInfo(){
        cout << "\nName: " << name << "\n"
             << "Balance: $" << balance << "\n"
             << "Bonus coin: $" << bonusCoin << "\n";
    }

};

int main(){
    RegularAcc a1("John", 1000);
    GoldAcc ga1("Gold John", 1000, 0);

    //Show info before paying
    a1.showInfo();
    ga1.showInfo();

    //Test paying function for both class
    a1.pay(1000);
    ga1.pay(1000);

    //Show info after paying
    a1.showInfo();
    ga1.showInfo();

    return 0;
}