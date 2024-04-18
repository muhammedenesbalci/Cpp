#include <iostream>

using namespace std;

//Definition of a class
class Country {
public:
    //Member variables
    string name;
    int population;
    string currency;
    string capital;

    //Member functions
    void description_of_this_object_of_class(string name);
};

void Country::description_of_this_object_of_class(string name) {
    cout << "This is an object of class: " << name << endl;
}

int main() {
    Country tr;
    tr.name = "Turkey";
    tr.population = 90000000;
    tr.currency = "TL";
    tr.capital = "Ankara";

    cout << "tr name: " << tr.name << endl;
    cout << "tr population: " << tr.population << endl;
    cout << "tr currency: " << tr.currency << endl;
    cout << "tr capital: " << tr.capital << endl;

    tr.description_of_this_object_of_class("tr");

    Country de;
    de.name = "germany";
    de.population = 83000000;
    de.currency = "Euro";
    de.capital = "Berlin";

    cout << "de name: " << de.name << endl;
    cout << "de population: " << de.population << endl;
    cout << "de currency: " << de.currency << endl;
    cout << "de capital: " << de.capital << endl;

    de.description_of_this_object_of_class("de");

    return 0;
}