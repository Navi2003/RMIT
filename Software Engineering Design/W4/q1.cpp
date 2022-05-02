#include <iostream>
#include <math.h>
class ComplNum{
private:
    double real, imag;
public:
    ComplNum(){};
    ComplNum(double real_val, double imag_val){
        this->real = real_val;
        this->imag = imag_val;
    }

    ComplNum operator - (ComplNum num){
        ComplNum tmp;
        tmp.real = this->real - num.real;
        tmp.imag = this->imag - num.imag;
        return tmp;
    }

    ComplNum operator - (double num){
        ComplNum tmp;
        tmp.real = this->real - num;
        tmp.imag = this->imag;
        return tmp;
    }

    friend ComplNum operator - (double num, ComplNum num2);

    ComplNum operator -- (){
        this->real--;
        return *this;
    }

    ComplNum operator -- (int){
         this->real--;
        return *this;
    }

    friend double abso(ComplNum num);
};

ComplNum operator - (double num, ComplNum num2){
    ComplNum tmp;
    tmp.real = num - num2.real;
    tmp.imag = num2.imag;
    return tmp;
}

double abso(ComplNum num){
    return sqrt(num.real*num.real + num.imag*num.imag);
}

int main(){
    
    return 0;
}















/*  
#include <iostream>
#include <sstream>
#include <cmath>

class ComplNum {
private: 
    double real;
    double imag;
public:
    ComplNum(){};

    ComplNum(double real, double imag){
        this->real = real;
        this->imag = imag;
    }

    std::string info(){
        std::stringstream sstr;
        sstr << real << " + " << imag << "i";
        return sstr.str();
    }

    //Define operator overloading function for compl - compl
    ComplNum operator - (ComplNum num2){
        ComplNum temp;
        temp.real = this->real - num2.real;
        temp.imag = this->imag - num2.imag;
        return temp;
    }      

    //Define operator overloading function for compl - double
    ComplNum operator -(double num2){
        ComplNum temp;
        temp.real = this->real - num2;
        temp.imag = this->imag;
        return temp;
    }
    friend ComplNum operator -(double num1, ComplNum num2);

    //Define operator overloading for -- (prefix)
    ComplNum operator -- (){
        --(this->real);
        return *this;
    }

    //Define operator overloading for -- (postfix)
    ComplNum operator -- (int){
        this->real--;
        return *this;
    }
        
        friend double abs (ComplNum num);
};

//double - obj
ComplNum operator -(double num1, ComplNum num2){
    ComplNum temp;
    temp.real = num1 - num2.real;
    temp.imag = -num2.imag;
    return temp;
}
//Return absolute value
double abs (ComplNum num){
    double temp;
    temp = sqrt(num.real*num.real+num.imag*num.imag);
    return temp;
}

int main(int argc, char *argv[]){
    ComplNum num1(5,5), num2(1,1), result(0,0);
    double num3 = 1;
    result = num1 - num2;
    std::cout << result.info() << "\n";
    std::cout << "Abs: " << abs(num1);
    return 0;
}
*/