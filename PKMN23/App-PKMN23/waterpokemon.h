#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H
#include "pokemon.h"


class WaterPokemon : public Pokemon
{
private:
    int itsNbFins ;
    float itsSpeed ;
public:
    WaterPokemon(string name, float height, float weight, int hp, int cp, int nbFins);
    ~WaterPokemon();
    void displayPokemon() ;
    int nbDamage(Pokemon * anOpponent);
    void attack(Pokemon * anOpponent);
    string getItsType();
};

#endif // WATERPOKEMON_H
