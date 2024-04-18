#include "RaceCar.h"
#include <iostream>

void RaceCar::turnContact() {
    this->fireUpEngine();
    this->pumpGasoline();
    this->startCylinders();
    this->startCylinders();

    this->kilometer();
    this->temperature();


    std::cout << "RaceCar: Turned Contact " << std::endl;

}