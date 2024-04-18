#include "Pikachu.h"
#include <iostream>

//Constructors
Pikachu::Pikachu() {
    std::cout << "Pikachu: Empty Constructor" << std::endl;
}

Pikachu::Pikachu(std::string name) : Pokemon(name) {
    this->name = name;
    std::cout << "Pikachu: with one parameter" << std::endl;
}

Pikachu::Pikachu(std::string name, std::string color) : Pokemon(name) {
    this->name = name;
    this->color = color;
    std::cout << "Pikachu: with two parameter" << std::endl;
}

//Getter and setter
std::string Pikachu::getColor() {
    std::cout << "Pikachu: getColor" << std::endl;
    return this->color;
}

void Pikachu::setColor(std::string name) {
    this->color = color;

    std::cout << "Pikachu: setColor" << std::endl;

}

//Member Function
void Pikachu::classNamePikachu() {
    std::cout << "Class name: Pikachu" << std::endl;
}

void Pikachu::classNameForOverriding() {
    std::cout << "Class name: Pikachu" << std::endl;
}

Pikachu::~Pikachu() {
    std::cout << "Pikachu: Destructor" << std::endl;
}

