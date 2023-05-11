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
    static int itsLevel;
    static int itsPoints;
    vector<Pokemon*> * itsPokemonTeam;

public:
    Trainer(string name);
    ~Trainer();

    void catchPokemon(Pokemon* pokemon);
    void removePokemon(Pokemon* pokemon);
    void attack(Trainer* anOpponentTrainer, Pokemon* myPokemon, Pokemon* anOpponentPokemon);

    void displayTrainer();
    float getItsAverageSpeed();
    int getItsTotalTeamHP();
    int getItsTotalCP();

    bool operator<(const Trainer& anOpponent);

    // Getters and setters
    string getItsName() const;
    int getItsLevel() const;
    int getItsPoints() const;
    vector<Pokemon*> getTeam() const;



    static void setItsPoints(int newItsPoints);
};


#endif // TRAINER_H
