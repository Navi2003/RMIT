/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Doan Tran Thien Phuc
  ID: 3926377
  Compiler used: gcc 8.1.0
  Created  date: 8/4/2022
  Acknowledgement: Lecture slides, Tutorialspoint
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

//Define class EWallet
class EWallet {
private:
	std::string id;
	double balance;
public:
	//Constructor
	EWallet(){};
	EWallet(std::string id_val, double balance_val){
		id = id_val;
		balance = balance_val;
	}

	std::string showInfo(){
		std::stringstream sstr;
		sstr << "ID: " << id << ", Balance: $" << balance;
		return sstr.str();
	}

	double returnBal(){
		return balance;
	}

	//Function to deposit money
	void deposit(double num){
		balance += num;
		std::cout << "$" << num << " added to balance of account ID: " << id << "\n" ;
	}

	//Function to withdraw money
	bool withdraw(double num){
		if (num > balance){
			std::cout << "Cannot withdraw more than balance\n";
			return 0;
		} else {
			balance -= num;
			std::cout << "$" << num << " subtracted from balance of account ID: " << id << "\n";
			return 1;
		}
	}

};

//b Define class customer
class Customer{
private:
	std::string name, pwd;
	EWallet ew;
public:
	//Constructor
	Customer(){};
	Customer(std::string name_val, std::string pwd_val, EWallet ew_val){
		name = name_val;
		pwd = pwd_val;
		ew = ew_val;
	}

	std::string showInfo(){
		std::stringstream sstr;
		sstr << "Name: " << name << ", Account info: " << ew.showInfo() << "\n";
		return sstr.str();
	}

	//Function to verify password
	bool verifyPass(){
		std::string pwd_input;
		std::cout << "Enter password: ";
		std::cin >> pwd_input;
		if (pwd_input == pwd){
			std::cout << "Login successful\n";
			return 1;
		} else {
			std::cout << "Incorrect password\n";
			return 0;
		}
	}

	//Function to deposit money (after verification)
	bool doDeposit(){
		if(verifyPass()){
			double dep;
			std::cout << "Enter the deposit amount: ";
			std::cin >> dep;
			ew.deposit(dep);
			return 1;
		} else {
			return 0;
		}
	}

	//Function to withdraw money (after verification)
	bool doWithdraw(){
		if(verifyPass()){
			double wit;
			std::cout << "Enter the deposit amount: ";
			std::cin >> wit;
			ew.withdraw(wit);
			return 1;
		} else {
			return 0;
		}
	}

	//c Initialize friend function for overloading >>
	friend void operator >> (Customer &cus1, Customer &cus2);

	//Overloading ++ (postfix)
	Customer operator ++(int){
		ew.deposit(1000);
		std::cout << "$1000 added to account\n";
		return *this;
	}
};

//Overloading >>
void operator >> (Customer &cus1, Customer &cus2){
	double tmp = cus1.ew.returnBal();
	cus1.ew.withdraw(tmp);
	cus2.ew.deposit(tmp);
}


int main(){
	//Initialize objects
	EWallet *acc1 = new EWallet("s123", 1000);
	EWallet *acc2 = new EWallet("s124", 500);
	EWallet *acc3 = new EWallet("s125", 1200);
	EWallet *acc4 = new EWallet("s126", 200);
	Customer cus1("Bob", "123456", *acc1);
	Customer cus2("Jog", "123456", *acc2);
	Customer cus3("Bog", "123456", *acc3);
	Customer cus4("Job", "123456", *acc4);

	//Test deposit and withdraw function of class EWallet
	std::cout << acc1->showInfo() << "\n";
	acc1->deposit(150);
	std::cout << acc1->showInfo() << "\n";
	acc1->withdraw(250);
	std::cout << acc1->showInfo() << "\n";
	
	//Test doDeposit and doWithdraw of class Customer
	std::cout << cus1.showInfo();
	cus1.doDeposit();
	std::cout << cus1.showInfo();
	cus1.doWithdraw();
	std::cout << cus1.showInfo();

	std::cout << "\n";
	//Test ++ and >> of class Customer
	std::cout << cus1.showInfo();
	std::cout << cus1++.showInfo();
	cus1 >> cus2;
	std::cout << cus1.showInfo();
	std::cout << cus2.showInfo();

	//d Array of customer and write to dataq2
	//Array
	Customer *cus_arr = new Customer[4]{cus1, cus2, cus3, cus4};

	//Write to file
	std::fstream myfile;
	myfile.open("dataq2.txt", std::ios::out);
	if(!myfile){
		std::cerr << "Failed to open file";
		return -1;
	}
	for (int i = 0; i < 4; i++){
		myfile << cus_arr[i].showInfo() << std::endl;
	}
	myfile.close();

	delete acc1, acc2, acc3, acc4, cus_arr;
	return 0;
}