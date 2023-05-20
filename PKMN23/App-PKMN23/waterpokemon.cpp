#include "waterpokemon.h"


WaterPokemon::WaterPokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp, int nbFins) :
    Pokemon(name, height, weight, maxHP, currentHP, cp), itsNbFins(nbFins), itsSpeed()
{
    itsSpeed = (itsWeight * itsNbFins) / 25.0;
    itsType = "WATER" ;
}

string WaterPokemon::getItsType()
{
    return itsType ;
}

string WaterPokemon::displayPokemon()
{
    stringstream description ;

    description << "Je suis le Pokemon " << itsName << "(type WATER). Mon poids est de " << itsWeight
                << "kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbFins
                << " nageoires, ma taille est de " << itsHeight << "m." ;

    return description.str();
}

int WaterPokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "FIRE")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "WATER" || anOpponent->getItsType() == "GRASS")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;
}

float WaterPokemon::getItsSpeed()
{
    return itsSpeed ;
}



