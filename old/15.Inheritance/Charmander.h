#include<iostream>
#include <string>

//Inheritance
#include "Pokemon.h"

class Charmander : public Pokemon {
protected:
    std::string color;
public:
    //Constructor
    Charmander();
    Charmander(std::string name);
    Charmander(std::string name, std::string color);

    //Getter Setter
    std::string getColor();
    void setColor(std::string name);

    //Member fucntion
    void classNamePikachu();
    void classNameForOverriding();
    void baseClassFunc_();
    void classNamePokemon_();

    //Destructor
    ~Charmander();
};


