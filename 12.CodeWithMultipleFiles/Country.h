#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>

using namespace std;

class Country {
private:
    string name;
    int population;
    string currency;
    string capital;
public:
    //Setter
    void setName(string name);

    void setPopulation(int population);

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

#endif