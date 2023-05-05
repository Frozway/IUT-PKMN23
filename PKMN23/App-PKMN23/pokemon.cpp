#include "pokemon.h"

Pokemon::Pokemon(string name, string type, float height, float weight, int hp, int cp) :
        itsName(name), itsType(type), itsHeight(height), itsWeight(weight), itsHP(hp), itsCP(cp) {}

void Pokemon::displayPokemon() const
{
    cout << "Name: " << itsName << endl;
    cout << "Type: " << itsType << endl;
    cout << "Height: " << itsHeight << endl;
    cout << "Weight: " << itsWeight << endl;
    cout << "HP: " << itsHP << endl;
    cout << "CP: " << itsCP << endl;
}
