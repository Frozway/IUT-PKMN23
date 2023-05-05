#include "waterpokemon.h"

WaterPokemon::WaterPokemon(string name, float height, float weight, int hp, int cp, int nbFins) :
    Pokemon(name, "WATER", height, weight, hp, cp), itsNbFins(nbFins)
{
    itsSpeed = (itsWeight * itsNbFins) / 25.0;
}

void WaterPokemon::displayPokemon() const
{
    Pokemon::displayPokemon();
    cout << "Nb Fins: " << itsNbFins << endl;
    cout << "Speed: " << itsSpeed << endl;
}

