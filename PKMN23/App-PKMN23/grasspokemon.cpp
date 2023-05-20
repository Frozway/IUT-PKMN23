#include "grasspokemon.h"

GrassPokemon::GrassPokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp) :
    Pokemon(name, height, weight, maxHP, currentHP, cp),  itsSpeed()
{
    itsSpeed = 10 / (itsWeight * itsHeight) ;
    itsType = "GRASS" ;
}

string GrassPokemon::getItsType()
{
    return itsType ;
}

string GrassPokemon::displayPokemon()
{
    stringstream description ;

    description << "Je suis le Pokemon " << itsName << "(type GRASS). Mon poids est de " << itsWeight
                << "kg, ma taille est de " << itsHeight << "m, ma vitesse est de " << itsSpeed << "km/h";

    return description.str();
}

int GrassPokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "ELECTRIK")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "FIRE" || anOpponent->getItsType() == "GRASS")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;
}

float GrassPokemon::getItsSpeed()
{
    return itsSpeed ;
}

