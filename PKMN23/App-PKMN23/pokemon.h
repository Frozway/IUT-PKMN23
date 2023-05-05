#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std ;


class Pokemon
{
protected:
    string itsName ;
    string itsType ;
    float itsHeight ;
    float itsWeight ;
    int itsHP ; //Heal point
    int itsCP ; //Combat power

public:
    Pokemon(string name, string type, float height, float weight, int hp, int cp);
    virtual ~Pokemon() {} // Ajout d'un destructeur virtuel
    virtual void displayPokemon() const = 0; // Déclaration de la méthode virtuelle pure display()
};

#endif // POKEMON_H
