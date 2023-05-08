#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std ;

/**
 * @brief The Pokemon class is the base class for all types of Pokemons in the game.
 */
class Pokemon
{
protected:
    string itsName ; /**< The name of the Pokemon */
    float itsHeight ; /**< The height of the Pokemon */
    float itsWeight ; /**< The weight of the Pokemon */
    int itsHP ; /**< The health points of the Pokemon */
    int itsCP ; /**< The combat points of the Pokemon */

public:
    /**
     * @brief Pokemon Constructor for the Pokemon class.
     * @param name The name of the Pokemon.
     * @param height The height of the Pokemon.
     * @param weight The weight of the Pokemon.
     * @param hp The health points of the Pokemon.
     * @param cp The combat points of the Pokemon.
     */
    Pokemon(string name, float height, float weight, int hp, int cp);

    virtual ~Pokemon() {};

    /**
     * @brief displayPokemon A pure virtual function that displays the information about the Pokemon.
     */
    virtual void displayPokemon() = 0;

    /**
     * @brief getItsType A pure virtual function that returns the type of the Pokemon.
     * @return The type of the Pokemon.
     */
    virtual string getItsType() = 0;

    /**
     * @brief nbDamage A pure virtual function that calculates the damage done by the Pokemon to its opponent.
     * @param anOpponent A pointer to the opponent Pokemon.
     * @return The damage done by the Pokemon to its opponent.
     */
    virtual int nbDamage(Pokemon * anOpponent) = 0;

    /**
     * @brief attack A function that represents the Pokemon attacking its opponent.
     * @param currentPokemon A pointer to the attacking Pokemon.
     * @param anOpponent A pointer to the opponent Pokemon.
     */
    void attack(Pokemon * currentPokemon, Pokemon * anOpponent) ;

    /**
     * @brief getItsHP A function that returns the health points of the Pokemon.
     * @return The health points of the Pokemon.
     */
    int getItsHP() const;

    /**
     * @brief getItsCP A function that returns the combat points of the Pokemon.
     * @return The combat points of the Pokemon.
     */
    int getItsCP() const;

    /**
     * @brief setItsHP A function that sets the health points of the Pokemon.
     * @param newItsHP The new health points of the Pokemon.
     */
    void setItsHP(int newItsHP);
};

#endif // POKEMON_H
