#include "grasspokemon.h"

GrassPokemon::GrassPokemon(string name, float height, float weight, unsigned int maxHP, unsigned int currentHP, unsigned int cp) :
    Pokemon(name, height, weight, maxHP, currentHP, cp),  itsSpeed()
{
    itsSpeed = 10 / (itsWeight * itsHeight) ;
}

string GrassPokemon::getItsType()
{
    return "PLANTE" ;
}

void GrassPokemon::displayPokemon()
{
    cout << "Je suis le Pokemon " << itsName << "(type PLANTE). Mon poids est de " << itsWeight
         << "kg, ma taille est de " << itsHeight << "m, ma vitesse est de " << itsSpeed << "km/h";
}

int GrassPokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "ELECTRIK")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "FEU" || anOpponent->getItsType() == "PLANTE")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;
}

float GrassPokemon::getItsSpeed()
{
    return itsSpeed ;
}

