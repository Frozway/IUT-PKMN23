#include "grasspokemon.h"

GrassPokemon::GrassPokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp) :
    Pokemon(name, height, weight, maxHP, currentHP, cp),  itsSpeed()
{
    itsSpeed = 10 / (itsWeight * itsHeight) ;
}

string GrassPokemon::getItsType()
{
    return "GRASS" ;
}

void GrassPokemon::displayPokemon()
{
    cout << itsName << " (" << getItsType() <<") | " << itsCurrentHP << " HP | " << itsCP << " PC | " << itsSpeed << " KM/H | " << endl ;
//    cout << "Je suis le Pokemon " << itsName << "(type GRASS). Mon poids est de " << itsWeight
//         << "kg, ma taille est de " << itsHeight << "m, ma vitesse est de " << itsSpeed << "km/h";
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

