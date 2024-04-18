#include <iostream>
#include "Country_.h"

using namespace std;

int main() {
    Country abd;

    cout << "-----------------------\n" << endl;

    Country tr("Turkey", 90000000, "TL", "Ankara");
    cout << "tr name: " << tr.getName() << endl;
    cout << "tr population: " << tr.getPopulaation() << endl;
    cout << "tr currency: " << tr.getCurrency() << endl;
    cout << "tr capital: " << tr.getCapital() << endl;
    tr.description_of_this_object_of_class("tr");

    cout << "-----------------------\n" << endl;

    Country de("germany", 83000000);

    de.setCurrency("Euro");
    de.setCapital("Berlin");

    cout << "de name: " << de.getName() << endl;
    cout << "de population: " << de.getPopulaation() << endl;
    cout << "de currency: " << de.getCurrency() << endl;
    cout << "de capital: " << de.getCapital() << endl;
    de.description_of_this_object_of_class("de");
    return 0;
}