#ifndef CPP_CAR_H
#define CPP_CAR_H

#include "Engine.h"
#include "Computer.h"


class Car : protected Engine, protected Computer{
public:
    void turnContact();
};


#endif //CPP_CAR_H
