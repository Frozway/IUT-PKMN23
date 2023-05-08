#include "pokemon.h"

Pokemon::Pokemon(string name, float height, float weight, int hp, int cp) :
        itsName(name), itsHeight(height), itsWeight(weight), itsHP(hp), itsCP(cp) {}


int Pokemon::getItsHP() const
{
    return itsHP;
}

int Pokemon::getItsCP() const
{
    return itsCP;
}

void Pokemon::setItsHP(int newItsHP)
{
    itsHP = newItsHP;
}

void Pokemon::attack(Pokemon * currentPokemon, Pokemon * anOpponent)
{
    anOpponent->setItsHP(anOpponent->getItsHP() - currentPokemon->nbDamage(anOpponent));
}
