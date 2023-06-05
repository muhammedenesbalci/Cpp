#include "Country_.h"

//Constructors
Country::Country() {
    cout << "Constructor: Empty" << endl;
}

Country::Country(string name) {
    this->name = name; // name = name

    cout << "Constructor: name" << endl;
}

Country::Country(string name, int population) {
    this->name = name; // name = name
    this->population = population;
    cout << "Constructor: name, population" << endl;

}

Country::Country(string name, int population, string currency) {
    this->name = name; // name = name
    this->population = population;
    this->currency = currency;

    cout << "Constructor: name, population, currency" << endl;
}

Country::Country(string name, int population, string currency, string capital) {
    this->name = name; // name = name
    this->population = population;
    this->currency = currency;
    this->capital = capital;

    cout << "Constructor: name, population, currency, capital" << endl;
}

//Destructor
Country::~Country() {
    cout << "Object destroyed" << endl;
}

// Setter
void Country::setName(string name) {
    this->name = name; // name = name
}

void Country::setPopulaation(int population) {
    this->population = population;
}

void Country::setCurrency(string currency) {
    this->currency = currency;
}

void Country::setCapital(string capital) {
    this->capital = capital;
}

//Getter
string Country::getName() {
    return this->name;
}

int Country::getPopulaation() {
    return this->population;
}

string Country::getCurrency() {
    return this->currency;
}

string Country::getCapital() {
    return this->capital;
}

void Country::description_of_this_object_of_class(string name) {
    cout << "This is an object of class: " << name << endl;
}


