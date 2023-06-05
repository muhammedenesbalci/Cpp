#include "Charmander.h"
#include <iostream>

//Constructors
Charmander::Charmander() {
    std::cout << "Charmander: Empty Constructor" << std::endl;
}

Charmander::Charmander(std::string name) : Pokemon(name) {
    this->name = name;
    std::cout << "Charmander: with one parameter" << std::endl;
}

Charmander::Charmander(std::string name, std::string color) : Pokemon(name) {
    this->name = name;
    this->color = color;
    std::cout << "Charmander: with two parameter" << std::endl;
}

//Getter and setter
std::string Charmander::getColor() {
    std::cout << "Charmander: getColor" << std::endl;
    return this->color;
}

void Charmander::setColor(std::string name) {
    this->color = color;

    std::cout << "Charmander: setColor" << std::endl;

}

//Member Function
void Charmander::classNamePikachu() {
    std::cout << "Class name: Charmander" << std::endl;
}

void Charmander::classNameForOverriding() {
    std::cout << "Class name: Charmander" << std::endl;
}
void Charmander::baseClassFunc_() {
    this->baseClassFunc();
    //Charmander::baseClassFunc();
}
void Charmander::classNamePokemon_() {
    Charmander::classNamePokemon();
}

Charmander::~Charmander() {
    std::cout << "Charmander: Destructor" << std::endl;
}

