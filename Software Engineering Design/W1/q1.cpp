#include <iostream>
#include <math.h>
int main(){
    int a, b, c, delta;
    float r1, r2;
    std::cout << "Enter a, b ,c: ";
    std::cin >> a >> b >> c;
    if (a == 0){
        if (b != 0){
        std::cout << "1 root: " << -c/b;
        } else if(c != 0) {
            std::cout << "No roots";
        } else {
            std::cout << "Infinite solutions";
        }
    } else {
        delta = b*b - 4*a*c;
        if (delta < 0){
            std::cout << "No roots";
        } else if (delta == 0){
            std::cout << "Double root: " << -b/(2*a);
        } else {
            r1 = (-b+sqrt(delta))/(2*a);
            r2 = (-b-sqrt(delta))/(2*a);
            std::cout << "2 roots: " << r1 << ", " << r2;
        }
    }
    return 0;
}

/*#include <iostream>
#include <cmath>

int main(){
    double a, b, c, x1, x2;
    std::cout << "Enter the value of a, b, c: ";
    std::cin >> a >> b >> c;
    
    if (a==0){
        if (b==0){
            if (c==0){
                std::cout << "There are infinite solutions.\n";
            } else {
                std::cout << "No roots.\n";
            }
        } else {
            std::cout << "One root: " << -c/b << "\n";
        }
    } else {
        double delta = b*b - 4*a*c;
        if (delta < 0){
            std::cout << "No roots.";
        } else if (delta == 0){
            std::cout << "One root: x1 = x2 =" << -b/(2*a) << "\n"; 
        } else {
            std::cout << "There are two roots: "
                      <<"x1 = " << (-b + sqrt(delta))/2*a
                      <<", x2 = " << (-b - sqrt(delta))/2*a; 
        }
    }
    return 0;
}
*/