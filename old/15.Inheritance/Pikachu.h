#include<iostream>
#include <string>

//Inheritance
#include "Pokemon.h"

class Pikachu : public Pokemon {
protected:
    std::string color;
public:
    //Constructor
    Pikachu();
    Pikachu(std::string name);
    Pikachu(std::string name, std::string color);

    //Getter Setter
    std::string getColor();
    void setColor(std::string name);

    //Member fucntion
    void classNamePikachu();
    void classNameForOverriding();

    //Destructor
    ~Pikachu();
};


