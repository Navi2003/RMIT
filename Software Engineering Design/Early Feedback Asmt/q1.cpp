#include <iostream>
#include <cstring>
#include <fstream>

//Define class
class BankAcc{
        public:
        std::string name;
        float amount;
        
        //Constructor
        BankAcc(std::string name_val, float amount_val) {
            name = name_val;
            amount = amount_val;
        }

        //Show account info method
        void show_info(){
            std::cout << "Name: " << name
                      << ", Amount: " << amount << "\n";
        }
        
        //Withdraw method
        int withdraw(float num){
            if (amount >= num){
                amount -= num;
                return 1;
            } else {
                std::cerr << "Cannot withdraw more than account balance \n";
                return -1;
            }
        }

};

int main(int argc, char* argv[]){

    //Initialize and printing out the account name and amount
    BankAcc acc1 ("Thien Phuc", 100.00), acc2 ("John Smith",75.25), acc3 ("Jesse", 90.50);
    acc1.show_info();
    acc2.show_info();
    acc3.show_info();

    //Test withdraw method
    acc1.withdraw(125);

    //Save data
    std::fstream myfile;
    if (argc == 2){//Save to file if there is a cmd line argument
        myfile.open(argv[1], std::ios::out);
        myfile << "Acc1: Name: " << acc1.name << ", Amount: " << acc1.amount << "\n"
               << "Acc2: Name: " << acc2.name << ", Amount: " << acc2.amount << "\n"
               << "Acc3: Name: " << acc3.name << ", Amount: " << acc3.amount << "\n";
        myfile.close();
    }
    return 0;
}