#include "Car.h"

#include <iostream>

void Car::turnContact() {
    this->fireUpEngine();
    this->pumpGasoline();
    this->startCylinders();

    std::cout << "Car: Turned Contact " << std::endl;
}