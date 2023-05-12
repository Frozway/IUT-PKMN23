#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>




class Trainer
{
private:
    string itsName;
    int itsLevel;
    int itsPoints;
    vector<Pokemon*> * itsPokemonTeam;

public:
    Trainer(string name);
    ~Trainer();

    void catchPokemon(Pokemon* pokemon);
    void removePokemon(Pokemon* pokemon);
    void attack(Pokemon* myPokemon, Pokemon* anOpponentPokemon);

    void displayTrainer();
    void displayTeam();
    void calculateLevel();

    float getItsAverageSpeed();
    float getItsAverageSpeed(string itsType);
    int getItsTotalTeamHP();
    int getItsTotalCP();
    void setItsPoints(int newItsPoints);

    // Getters and setters
    string getItsName() const;
    int getItsLevel() const;
    int getItsPoints() const;
    vector<Pokemon*> getTeam() const;
};


#endif // TRAINER_H
