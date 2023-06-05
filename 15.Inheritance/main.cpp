#include <iostream>

#include "Pikachu.h"
#include "Charmander.h"

using namespace std;

int main() {

    // Public Inheritance
    //Empty
    cout <<"Empty-------------------------------------------" <<endl;
    Pikachu pikachu_empty;


    //Pikachu one parameter
    cout <<"One Parameter-------------------------------------------" <<endl;

    Pikachu pikachu_one("Pikachu");
    cout << pikachu_one.getName() << endl;

    pikachu_one.setName("Pikachuuu");
    cout << pikachu_one.getName() << endl;

    //Pikachu two parameter
    cout <<"two Parameter-------------------------------------------" <<endl;

    Pikachu pikachu_two("Pikachu", "blue");

    cout << pikachu_two.getName() << endl;
    cout << pikachu_two.getColor() << endl;

    pikachu_two.setName("Pikachuuu");
    pikachu_two.setColor("Yellow");

    cout << pikachu_two.getName() << endl;
    cout << pikachu_two.getColor() << endl;

    //Member functions
    pikachu_two.baseClassFunc();

    pikachu_two.classNamePikachu();
    pikachu_two.classNamePokemon();

    pikachu_two.classNameForOverriding();

    // Private Inheritance
    //Empty
    /*
    cout <<"Empty-------------------------------------------" <<endl;
    Charmander charmander_empty;


     we can't access anything of the main class from outside unless you do overriding
    //Pikachu one parameter
    cout <<"One Parameter-------------------------------------------" <<endl;

    Charmander charmander_one("Charmander");
    cout << charmander_one.getName() << endl;

    charmander_one.setName("Charmanderrr");
    cout << charmander_one.getName() << endl;

    //Pikachu two parameter
    cout <<"two Parameter-------------------------------------------" <<endl;

    Charmander charmander_two("Charmander", "blue");

    cout << charmander_two.getName() << endl;
    cout << charmander_two.getColor() << endl;

    charmander_two.setName("Charmanderrrr");
    charmander_two.setColor("Yellow");

    cout << charmander_two.getName() << endl;
    cout << charmander_two.getColor() << endl;
*/

    Charmander charmander_two("Charmander", "blue");
    charmander_two.baseClassFunc_();

    charmander_two.classNamePikachu();
    charmander_two.classNamePokemon_();

    charmander_two.classNameForOverriding();


    return 0;

}