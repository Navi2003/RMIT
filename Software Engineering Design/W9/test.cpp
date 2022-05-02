#include <iostream>
using std::string;
using std::cout;
class HouseHold{
public:
string name;
HouseHold *purchasedPerson = NULL;
HouseHold (string name) {this->name = name; }
};

int main(){

/* Initialize nodes */
HouseHold hh1("HouseHold 1"), hh2("HouseHold 2"), hh3("HouseHold 3");

/* Save reference of first node in head (orginal HouseHold)*/
HouseHold *origHouseHold = &hh1;

/* Connect nodes */
hh1.purchasedPerson = &hh2;
hh2.purchasedPerson = &hh3;

/* Loop through the linked list */
printf("\nLinked Households are: \n");
HouseHold *temp = origHouseHold;
while (temp != NULL) {
cout << temp->name << " --> ";
temp = temp->purchasedPerson; //access next node
}
}