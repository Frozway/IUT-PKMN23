#include "electrikpokemon.h"

ElectrikPokemon::ElectrikPokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp, int nbLegs, int nbWings, int intensity) :
    Pokemon(name, height, weight, maxHP, currentHP, cp), itsNbLegs(nbLegs), itsNbWings(nbWings), itsIntensity(intensity), itsSpeed()
{
    itsSpeed = (itsNbLegs + itsNbWings) * itsIntensity * 0.05 ;
    itsType = "ELECTRICK";
}

string ElectrikPokemon::getItsType()
{
    return itsType ;
}

string ElectrikPokemon::displayPokemon()
{
    stringstream description ;

    description << "Je suis le Pokemon " << itsName << "(type ELECTRIK). Mon poids est de " << itsWeight
                << "kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbLegs
                << " pattes, ma taille est de " << itsHeight << " m et mon intensité est de " << itsIntensity << " mA." ;

    return description.str();
}

int ElectrikPokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "EAU")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "ELECTRIK" || anOpponent->getItsType() == "GRASS")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;

}

float ElectrikPokemon::getItsSpeed()
{
    return itsSpeed ;
}


