#include <iostream>
#include "pokemon.h"
#include "waterpokemon.h"

using namespace std;

int main()
{
    Pokemon* carapuce = new WaterPokemon("Carapuce", 2, 2, 2, 2, 2);

    cout << "Hello World!" << endl;
    return 0;
}
