/**
* @brief The Pokemon class
* The Pokemon class is the base class for all types of Pokemons in the game.
* @author Thibaut LEFRANCOIS
* @version 1.0
* @date May 2023
* @copyright Thibaut LEFRANCOIS
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std ;

class Pokemon
{
protected:
    string itsName ; /**< The name of the Pokemon */
    float itsHeight ; /**< The height of the Pokemon */
    float itsWeight ; /**< The weight of the Pokemon */
    unsigned int itsMaxHP ; /**< The max health points of the Pokemon */
    unsigned int itsCurrentHP ; /**< The current health points of the Pokemon */
    unsigned int itsCP ; /**< The combat points of the Pokemon */

public:
    /**
     * @brief Pokemon Constructor for the Pokemon class.
     * @param name The name of the Pokemon.
     * @param height The height of the Pokemon.
     * @param weight The weight of the Pokemon.
     * @param hp The health points of the Pokemon.
     * @param cp The combat points of the Pokemon.
     */
    Pokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp);

    //virtual ~Pokemon() {};

    /**
     * @brief displayPokemon A pure virtual function that return the information about the Pokemon.
     */
    virtual string displayPokemon() = 0;

    /**
     * @brief getItsType A pure virtual function that returns the type of the Pokemon.
     * @return The type of the Pokemon.
     */
    virtual string getItsType() = 0;

    /**
     * @brief getItsSpeed A pure virtual function that returns the speed of the Pokemon.
     * @return The speed of the Pokemon.
     */
    virtual float getItsSpeed() = 0;

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
    void attack(Pokemon * anOpponent) ;

    /**
     * @brief getItsNale A function that returns the name of the Pokemon.
     * @return The name of the Pokemon.
     */
    string getItsName() const;

    /**
     * @brief getItsHP A function that returns the max health points of the Pokemon.
     * @return The health points of the Pokemon.
     */
    int getItsMaxHP() const;

    /**
     * @brief getItsHP A function that returns the current health points of the Pokemon.
     * @return The health points of the Pokemon.
     */
    int getItsCurrentHP() const;

    /**
     * @brief getItsCP A function that returns the combat points of the Pokemon.
     * @return The combat points of the Pokemon.
     */
    int getItsCP() const;

    /**
     * @brief getItsHeight A function that returns the height of the Pokemon.
     * @return The height of the Pokemon.
     */
    float getItsHeight() const;

    /**
     * @brief getItsWeight A function that returns the weight of the Pokemon.
     * @return The weight of the Pokemon.
     */
    float getItsWeight() const;

    /**
     * @brief setItsHP A function that sets the health points of the Pokemon.
     * @param newItsHP The new health points of the Pokemon.
     */
    void setItsHP(int newItsHP);
};

#endif // POKEMON_H
