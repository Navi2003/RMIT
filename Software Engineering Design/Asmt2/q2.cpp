/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 2
  Author: Doan Tran Thien Phuc
  ID: s3926377
  Compiler used: gcc 8.1.0
  Created  date: 6/5/2022
  Acknowledgement: lecture slides, previous tutorials, programiz
*/

#include <iostream>

using namespace std;

class City{
//Declare attributes
private:
    string name;
    double days;
    City *nextCity;

public:
    //Constructors
    City(){};
    City(string name, double days){
        this->name = name;
        this->days = days;
    }

    //Function to set link
    void setLink(City *nextCity){
        this->nextCity = nextCity;
    }

    friend void printTripPlan(City *&first);
    friend void printAdjacentLongestAndShortestStay(City *&first, City *&last);
    friend bool insertCity(City *&first, City *&last, City *newCity, City *latterCity);
    friend bool searchCity(City *&first, City *search);
};

//Function to search if the city is in the plan
bool searchCity(City *&first, City *search){
        City *current = first;
        while (current != NULL){
            if (current == search){
                return 1;
            }
            current = current->nextCity;
        }
        return 0;
    }

//a Function to print forward the trip plan
void printTripPlan(City *&first){
    City *current = first;
    while (current != NULL){
        cout << current->name << ": " << current->days << " day";
        cout << ((current->days == 1)?"\n":"s\n");
        current = current->nextCity;
    }
}


//b Function to print out the answer to question b
void printAdjacentLongestAndShortestStay(City *&first, City *&last){
    City *current = first, *lAd = first, *sAd = first;
    double longestStayLength = lAd->days + lAd->nextCity->days;
    double shortestStayLength = sAd->days + sAd->nextCity->days;
    while (current->nextCity != NULL){
        if (longestStayLength < (current->days + current->nextCity->days)){
            longestStayLength = current->days + current->nextCity->days;
            lAd = current;
        }
        if (shortestStayLength > (current->days + current->nextCity->days)){
            shortestStayLength = current->days + current->nextCity->days;
            sAd = current;
        }
        current = current->nextCity;
    }
    cout << "Adjacent cities with longest stay length: " << lAd->name << " & " << lAd->nextCity->name << "\n"
         << "Total staying time : " << longestStayLength << " days\n";
    cout << "Adjacent cities with shortest stay length: " << sAd->name << " & " << sAd->nextCity->name << "\n"
         << "Total staying time : " << shortestStayLength << " days\n";
}

//c Function to insert a city into the plan
bool insertCity(City *&first, City *&last, City *newCity, City *latterCity){
    City *current = first;
    if (latterCity == first){
        newCity->nextCity = first;
        first = newCity;
        return 1;
    } else if (latterCity == NULL){
        last->nextCity = newCity;
        last = newCity;
        return 1;
    } else if (searchCity(first, latterCity) == 1) {
        while (current != NULL){
            if(current->nextCity == latterCity){
                current->nextCity = newCity;
                newCity->nextCity = latterCity;
            }
            current = current->nextCity;
        }
        return 1;
    } else return 0;
}


int main(){
    City c1("Hue", 2.5), c2("Da Nang", 1.5), c3("Nha Trang", 4), c4("Da Lat", 2), c5("Can Tho", 1), c6("Sai Gon", 2);

    //Set links
    c1.setLink(&c2);
    c2.setLink(&c3);
    c3.setLink(&c4);
    c4.setLink(&c5);
    c5.setLink(NULL);

    City *first = &c1, *last = &c5;

    //Test print trip plan
    printTripPlan(first);
    cout << "\n";

    //Print answer to question b
    printAdjacentLongestAndShortestStay(first, last);
    cout << "\n";

    //Inserting Sai Gon to the trip plan 
    insertCity(first, last, &c6, &c5);
    printTripPlan(first);
    return 0;
}