#include <iostream>
#include <string>
/*
 In object-oriented programming, a constructor is a special member function of a class that is used to initialize
 objects of that class. It is typically called automatically when an object is created.

The constructor has the same name as the class and does not have a return type (not even void). It is responsible
 for initializing the member variables of the class and performing any necessary setup operations. Constructors are
 commonly used to ensure that objects start in a valid and consistent state
 */

/*

In C++, a destructor is a special member function of a class that is used to clean up resources and perform any
 necessary cleanup operations before an object is destroyed or goes out of scope.

The destructor has the same name as the class preceded by a tilde (~) character and does not take any parameters or
 have a return type (not even void). It is called automatically when an object is destroyed, either explicitly or when
 it goes out of scope.*/

using namespace std;

class Country {
private:
    string name;
    int population;
    string currency;
    string capital;
public:
    //Constructors
    Country();

    Country(string name);

    Country(string name, int population);

    Country(string name, int population, string currency);

    Country(string name, int population, string currency, string capital);

    //Destructor
    ~Country();

    //Setter
    void setName(string name);

    void setPopulaation(int population);

    void setCurrency(string currency);

    void setCapital(string capital);

    //Getter
    string getName();

    int getPopulaation();

    string getCurrency();

    string getCapital();

    //Member function
    void description_of_this_object_of_class(string name);


};