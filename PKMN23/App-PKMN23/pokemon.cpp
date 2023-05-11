#include "pokemon.h"

Pokemon::Pokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp) :
        itsName(name), itsHeight(height), itsWeight(weight), itsMaxHP(maxHP), itsCurrentHP(currentHP), itsCP(cp) {}


int Pokemon::getItsMaxHP() const
{
    return itsMaxHP;
}

int Pokemon::getItsCurrentHP() const
{
    return itsCurrentHP;
}

int Pokemon::getItsCP() const
{
    return itsCP;
}

void Pokemon::setItsHP(int newItsHP)
{
    itsCurrentHP = newItsHP;
}

void Pokemon::attack(Pokemon * anOpponent)
{
    anOpponent->setItsHP(anOpponent->getItsCurrentHP() - this->nbDamage(anOpponent));
}
