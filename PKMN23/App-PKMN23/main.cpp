#include <iostream>
#include "pokemon.h"
#include "waterpokemon.h"

using namespace std;

int main()
{
    Pokemon * Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 30, 4);
    Carapuce->displayPokemon() ;
    int CP = Carapuce->getItsCP();

    return 0;
}
