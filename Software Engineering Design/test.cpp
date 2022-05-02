#include <iostream>
#include <sstream>
 
using namespace std;

void changeInt(int *num){
    *num = 6;
}
 

int main() {
    int num = 5;
    changeInt(&num);
    cout << num; 
    return 0;
}