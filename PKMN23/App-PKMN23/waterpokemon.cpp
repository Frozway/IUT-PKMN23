#include "waterpokemon.h"

WaterPokemon::WaterPokemon(string name, float height, float weight, int hp, int cp, int nbFins) :
    Pokemon(name, height, weight, hp, cp), itsNbFins(nbFins), itsSpeed()
{
    itsSpeed = (itsWeight * itsNbFins) / 25.0;
}

string WaterPokemon::getItsType()
{
    return "EAU" ;
}

void WaterPokemon::displayPokemon()
{
    cout << "Je suis le Pokemon " << itsName << "(type EAU). Mon poids est de " << itsWeight
         << "kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbFins
         << " nageoires, ma taille est de " << itsHeight << " m." ;
}

int WaterPokemon::nbDamage(Pokemon * anOpponent)
{
    if(anOpponent->getItsType() == "FEU")
    {
        return 2 * itsCP;
    }
    else if(anOpponent->getItsType() == "EAU" || anOpponent->getItsType() == "PLANTE")
    {
        return 0.5 * itsCP ;
    }
    else return itsCP ;

}

void attack(Pokemon * currentPokemon, Pokemon * anOpponent)
{
    //int currentOpponentHP = anOpponent->getItsHP() ;
    //currentOpponentHP -= currentPokemon->nbDamage(anOpponent) ;
    //anOpponent->setItsHP(currentOpponentHP);
    anOpponent->setItsHP(anOpponent->getItsHP() - currentPokemon->nbDamage(anOpponent));
}
