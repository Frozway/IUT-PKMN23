#include "electrikpokemon.h"

ElectrikPokemon::ElectrikPokemon(string name, float height, float weight, int hp, int cp, int nbLegs, int nbWings, int intensity) :
    Pokemon(name, height, weight, hp, cp), itsNbLegs(nbLegs), itsNbWings(nbWings), itsIntensity(intensity), itsSpeed()
{
    itsSpeed = (itsNbLegs + itsNbWings) * itsIntensity * 0.05 ;
}

string ElectrikPokemon::getItsType()
{
    return "ELECTRIK" ;
}

void ElectrikPokemon::displayPokemon()
{
    cout << "Je suis le Pokemon " << itsName << "(type ELECTRIK). Mon poids est de " << itsWeight
         << "kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbLegs
         << " pattes, ma taille est de " << itsHeight << " m et mon intensité est de " << itsIntensity << " mA." ;
}

int ElectrikPokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "EAU")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "ELECTRIK" || anOpponent->getItsType() == "PLANTE")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;

}

