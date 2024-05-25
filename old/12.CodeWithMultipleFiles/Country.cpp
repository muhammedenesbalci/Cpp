#include "Country.h"

// Setter
void Country::setName(string name) {
    this->name = name; // name = name
}

void Country::setPopulation(int population) {
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
