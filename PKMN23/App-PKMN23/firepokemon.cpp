#include "firepokemon.h"

FirePokemon::FirePokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp, int nbLegs) :
    Pokemon(name, height, weight, maxHP, currentHP, cp), itsNbLegs(nbLegs), itsSpeed()
{
    itsSpeed = itsNbLegs * itsWeight * 0.03 ;
}

string FirePokemon::getItsType()
{
    return "FIRE" ;
}

void FirePokemon::displayPokemon()
{
    cout << itsName << " (" << getItsType() <<") | " << itsCurrentHP << " HP | " << itsCP << " PC | " << itsSpeed << " KM/H | " << endl ;
//    cout << "Je suis le Pokemon " << itsName << "(type FIRE). Mon poids est de " << itsWeight
//         << "kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbLegs
//         << " pattes, ma taille est de " << itsHeight << "m." ;
}

int FirePokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "GRASS")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "EAU" || anOpponent->getItsType() == "ELECTRIK")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;
}

float FirePokemon::getItsSpeed()
{
    return itsSpeed ;
}


