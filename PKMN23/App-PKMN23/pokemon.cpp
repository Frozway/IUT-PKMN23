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
    //Si le nombre de dégats infligé emmène le pokémon à 0 ou moins de 0 HP, le mettre à 0 pour être sur
    if( (anOpponent->getItsCurrentHP() - this->nbDamage(anOpponent)) <= 0 )
    {
        anOpponent->setItsHP(0);
        this->setItsHP(this->itsMaxHP);

    }
    //Sinon lui infligé le nombre de dégat normal
    else
    {
        //Actualiser le nombre de points de vie de l'ennemie selon le nombre de dégats que notre pokémon peut lui faire
        anOpponent->setItsHP(anOpponent->getItsCurrentHP() - this->nbDamage(anOpponent));
    }





    /*

    //Si il est mort, s'assurer que sa vie est à 0 et redonner la vie au pokémon victorieux
    if(anOpponent->itsCurrentHP <= 0)
    {
        anOpponent->setItsHP(0);
        this->setItsHP(this->itsMaxHP);
    } */
}
