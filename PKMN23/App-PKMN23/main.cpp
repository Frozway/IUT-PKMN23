#include <iostream>
#include "pokemon.h"
#include "waterpokemon.h"

using namespace std;

int main()
{
    Pokemon * Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 100, 50, 4);

    Carapuce->displayPokemon() ;

    return 0;
}
