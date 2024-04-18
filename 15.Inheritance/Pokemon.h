#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>


class Pokemon {

protected:
    std::string name;

public:
    //Constructors
    Pokemon();

    Pokemon(std::string name);

    //Getter Setter
    void setName(std::string name);

    std::string getName();

    //Member function
    void classNamePokemon();
    void classNameForOverriding();
    void baseClassFunc();

    //Destructor
    ~Pokemon();
};

#endif