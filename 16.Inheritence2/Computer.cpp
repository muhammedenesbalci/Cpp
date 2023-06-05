#include "Computer.h"
#include <iostream>
#include <math.h>

void Computer::kilometer(){
    std::cout << "Kilometer: " << std::rand() * 1000 << std::endl;
}

void Computer::temperature(){
    std::cout << "Temperature: " << std::rand() % 40 << std::endl;
}
