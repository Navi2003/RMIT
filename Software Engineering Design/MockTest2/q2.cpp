#include <iostream>

using namespace std;

class Broker{
public:
    string name;
    int buyPrice;
    int sellPrice;
    Broker *nextBuyer = NULL;

    Broker(){};
    Broker(string name, int buyPrice, int sellPrice){
        this->name = name;
        this->buyPrice = buyPrice;
        this->sellPrice = sellPrice;
    }

    void setLink(Broker *nextBuyer){
        this->nextBuyer = nextBuyer;
    }

    int returnProf(){
        return sellPrice - buyPrice;
    }
    
};

void printTransaction(Broker *b){
    cout << "\n" << b->name << ": Initially bought the house for $" << b->buyPrice << "\n";
    b->nextBuyer;
    while (b->nextBuyer != NULL){
        cout << b->name << " --> " << b->nextBuyer->name << " :  price = $" << b->sellPrice << "\n";
        b = b->nextBuyer;
    }
}

void printHighestProf(Broker *&first, Broker *&last){
    Broker *high = first, *low = first, *left = first;
    while(left != last){
        if(high->returnProf() < left->returnProf()){
            high = left;
        }
        if(low->returnProf() > left->returnProf()){
            low = left;
        }
        left = left->nextBuyer;
    }
    cout << "\nHighest profit broker: " << high->name << "\n"
         << "Lowest profit broker: " << low->name << "\n";
}

void deleteTransaction(Broker *&first, Broker *&last, Broker *b){
    Broker *left = first;
    if (b == first){
        first = b->nextBuyer;
        b->nextBuyer = NULL;
    } else if (b->nextBuyer == last){
        last = b;
        b->nextBuyer = NULL;
    } else {
        while(1){
            if (left->nextBuyer == b){
                left->nextBuyer = b->nextBuyer;
                break;
            }
            left = left->nextBuyer;
        }
    }


}

int main(){
    Broker b1("David", 800, 1000), b2("John", 1000, 1200), b3("Peter", 1200, 1800), b4("Luna", 1800, 3500), b5("Sophia", 3500, 0);
    Broker *first = &b1, *last = &b5;
    b1.setLink(&b2);
    b2.setLink(&b3);
    b3.setLink(&b4);
    b4.setLink(&b5);
    b5.setLink(NULL);

    printTransaction(first);

    printHighestProf(first, last);

    deleteTransaction(first, last, &b5);

    printTransaction(first);
    return 0;
}