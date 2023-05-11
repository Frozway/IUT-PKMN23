#include <iostream>
#include "pokemon.h"
#include "waterpokemon.h"
#include "firepokemon.h"

using namespace std;

int main()
{
    Pokemon * Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 70, 30, 4);
    Pokemon * Salameche = new FirePokemon("Salameche", 0.65, 12, 70, 70, 30, 2);
    //Carapuce->displayPokemon() ;

    Carapuce->attack(Salameche) ;
    Carapuce->attack(Salameche) ;
    cout << Salameche->getItsCurrentHP() ;

    return 0;
}
