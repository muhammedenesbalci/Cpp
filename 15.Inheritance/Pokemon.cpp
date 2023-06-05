#include "Pokemon.h"
#include <iostream>

//Constructors
Pokemon::Pokemon() {
    std::cout << "Pokemon: Empty Constructor" << std::endl;
}

Pokemon::Pokemon(std::string name) {
    this->name = name;
    std::cout << "Pokemon: with one parameter" << std::endl;
}

//Member Function
void Pokemon::classNamePokemon() {
    std::cout << "Class name: Pokemon" << std::endl;
}

void Pokemon::classNameForOverriding() {
    std::cout << "Class name: Pokemon" << std::endl;
}

void Pokemon::baseClassFunc() {
    std::cout << "Class name: Pokemon base class" << std::endl;
}


//Getter Setter
void Pokemon::setName(std::string name) {
    std::cout << "Pokemon: setName" << std::endl;
    this->name = name;
}

std::string Pokemon::getName() {
    std::cout << "Pokemon: getName" << std::endl;
    return this->name;
}

Pokemon::~Pokemon() {
    std::cout << "Pokemon: Destructor" << std::endl;
}