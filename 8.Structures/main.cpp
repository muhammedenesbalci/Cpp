#include <iostream>
#include <string>

using namespace std;

//Structures
struct Country {
    string name;
    int population;
    string currency;
    string capital;
};

Country create_country(string name, int population, string currency, string capital) {
    Country my_country;
    my_country.name = name;
    my_country.population = population;
    my_country.currency = currency;
    my_country.capital = capital;

    return my_country;
}

int main() {
    cout << "Structures---------------------------------------------------------------------------------------" << endl;

    Country tr;
    tr.name = "Turkey";
    tr.population = 90000000;
    tr.currency = "TL";
    tr.capital = "Ankara";

    Country de;
    de.name = "germany";
    de.population = 83000000;
    de.currency = "Euro";
    de.capital = "Berlin";

    cout << "tr name: " << tr.name << endl;
    cout << "tr population: " << tr.population << endl;
    cout << "tr currency: " << tr.currency << endl;
    cout << "tr capital: " << tr.capital << endl;

    cout << "de name: " << de.name << endl;
    cout << "de population: " << de.population << endl;
    cout << "de currency: " << de.currency << endl;
    cout << "de capital: " << de.capital << endl;

    Country usa = create_country("United States of America", 331000000, "Dolar", "Washington DC");
    cout << "usa name: " << usa.name << endl;
    cout << "usa population: " << usa.population << endl;
    cout << "usa currency: " << usa.currency << endl;
    cout << "usa capital: " << usa.capital << endl;

    return 0;
}