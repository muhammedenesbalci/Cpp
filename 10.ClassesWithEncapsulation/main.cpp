#include <iostream>

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

int main() {
    Country tr;
    tr.setName("Turkey");
    tr.setPopulaation(90000000);
    tr.setCurrency("TL");
    tr.setCapital("Ankara");

    cout << "tr name: " << tr.getName() << endl;
    cout << "tr population: " << tr.getPopulaation() << endl;
    cout << "tr currency: " << tr.getCurrency() << endl;
    cout << "tr capital: " << tr.getCapital() << endl;

    tr.description_of_this_object_of_class("tr");

    Country de;
    de.setName("germany");
    de.setPopulaation(83000000);
    de.setCurrency("Euro");
    de.setCapital("Berlin");

    cout << "de name: " << de.getName() << endl;
    cout << "de population: " << de.getPopulaation() << endl;
    cout << "de currency: " << de.getCurrency() << endl;
    cout << "de capital: " << de.getCapital() << endl;

    de.description_of_this_object_of_class("de");

    return 0;
}