/**
 * @brief The Trainer class
 * The Trainer class represents a trainer in the Pokémon game. It manages a team of Pokémon and performs various operations related to the trainer and their team.
 *
 * @author Thibaut LEFRANCOIS
 * @version 0.2
 * @date May 2023
 */

#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

class Trainer
{
private:
    string itsName; /**< The name of the trainer */
    int itsLevel; /**< The level of the trainer */
    int itsPoints; /**< The points earned by the trainer */
    Pokemon * fighterPokemon ; /**< The Pokemon that is chosen to fight */
    vector<Pokemon*> * itsPokemonTeam; /**< The team of Pokemon owned by the trainer */

public:

    /**
     * @brief Trainer constructor.
     * @param name The name of the trainer.
     */
    Trainer(string name);

    /**
     * @brief ~Trainer destructor.
     * Cleans up the dynamically allocated memory for the Pokémon team.
     */
    ~Trainer();

    /**
     * @brief catchPokemon Adds a Pokémon to the trainer's team.
     * @param pokemon A pointer to the Pokémon to be added.
     */
    void catchPokemon(Pokemon* pokemon);

    /**
     * @brief removePokemon Removes a Pokémon from the trainer's team.
     * @param pokemon A pointer to the Pokémon to be removed.
     */
    void removePokemon(Pokemon* pokemon);

    /**
     * @brief attack Makes the trainer's Pokémon attack the opponent's Pokémon.
     * @param myPokemon A pointer to the attacking Pokémon.
     * @param anOpponentPokemon A pointer to the opponent's Pokémon.
     */
    void attack(Pokemon* myPokemon, Trainer * anOpponentTrainer, Pokemon* anOpponentPokemon);

    /**
     * @brief Checks if a Pokemon is present in the trainer's team.
     *
     * This function iterates through the trainer's Pokemon team and checks if the given Pokemon
     * is present in the team.
     *
     * @param pokemon A pointer to the Pokemon to be checked.
     * @return True if the Pokemon is in the trainer's team, false otherwise.
     */
    bool isPokemonInTeam(Pokemon* pokemon);

    /**
     * @brief displayTrainer Displays information about the trainer, including their level, points, and team details.
     */
    void displayTrainer();

    /**
     * @brief displayTeam Displays the Pokémon team of the trainer, along with their respective numbers.
     */
    void displayTeam();

    /**
     * @brief calculateLevel Calculates the level of the trainer based on their points.
     */
    void calculateLevel();

    /**
     * @brief getItsAverageSpeed Calculates the average speed of the trainer's Pokémon team.
     * @return The average speed of the Pokémon team.
     */
    float getItsAverageSpeed();

    /**
     * @brief getItsAverageSpeed Calculates the average speed of the trainer's Pokémon team for a specific type.
     * @param itsType The type of Pokémon to consider.
     * @return The average speed of the Pokémon team for the specified type.
     */
    float getItsAverageSpeed(string itsType);

    /**
     * @brief getItsTotalTeamHP Calculates the total health points of the trainer's Pokémon team.
     * @return The total health points of the Pokémon team.
     */
    int getItsTotalTeamHP();

    /**
     * @brief getItsTotalCP Calculates the total combat points of the trainer's Pokémon team.
     * @return The total combat points of the Pokémon team.
     */
    int getItsTotalCP();

    /**
     * @brief getItsLevel Retrieves the level of the trainer.
     * @return The level of the trainer.
     */
    int getItsLevel();

    /**
     * @brief getItsPoints Retrieves the points earned by the trainer.
     * @return The points earned by the trainer.
     */
    int getItsPoints();

    /**
     * @brief getItsName Retrieves the name of the trainer.
     * @return The name of the trainer.
    */
    string getItsName();

    /**
     * @brief getItsTeam Retrieves the Pokémon team of the trainer.
     * @return The Pokémon team of the trainer.
     */
    vector<Pokemon*> getItsTeam();

    /**
     * @brief setItsPoints Sets the points earned by the trainer.
     * @param newItsPoints The new points earned by the trainer.
     */
    void setItsPoints(int newItsPoints);

    bool allPokemonsDead() ;
    void setItsName(const string &newItsName);

    void setFighterPokemon(Pokemon *newFighterPokemon);

    Pokemon* getNextAlivePokemon();



    Pokemon *getFighterPokemon();
};

#endif // TRAINER_H
