/**
* @brief The WaterPokemon class represents a water-type Pokemon.
* It inherits from the Pokemon class and adds additional attributes
* specific to water-type Pokemon, such as its number of fins and speed.
* @author Thibaut LEFRANCOIS
* @version 0.1
* @date May 2023
* @copyright Thibaut LEFRANCOIS
*/

#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H

#include "pokemon.h"


class WaterPokemon : public Pokemon
{
private:
    int itsNbFins ; /**< The number of fins the WaterPokemon has. */
    float itsSpeed ; /**< The speed of the WaterPokemon. */
    string itsType ; /**< The type of the WaterPokemon. */

public:
    /**
     * @brief Construct a new Water Pokemon object.
     *
     * @param name The name of the WaterPokemon.
     * @param height The height of the WaterPokemon.
     * @param weight The weight of the WaterPokemon.
     * @param maxHP The max health points of the WaterPokemon.
     * @param currentHP The current health points of the WaterPokemon.
     * @param cp The combat points of the WaterPokemon.
     * @param nbFins The number of fins the WaterPokemon has.
     */
    WaterPokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp, int nbFins);

    /**
     * @brief Display the details of the WaterPokemon.
     *
     * This method overrides the displayPokemon() method in the Pokemon class
     * to include the additional attributes specific to WaterPokemon.
     */
    void displayPokemon() ;

    /**
     * @brief Calculate the damage inflicted on an opponent.
     *
     * This method calculates the damage inflicted on an opponent Pokemon
     * based on the combat points and type advantage of the WaterPokemon.
     *
     * @param anOpponent A pointer to the opponent Pokemon.
     * @return The damage inflicted on the opponent.
     */
    int nbDamage(Pokemon * anOpponent);

    /**
     * @brief Get the type of the WaterPokemon.
     *
     * This method overrides the getItsType() method in the Pokemon class
     * to return the string "WATER", which is the type of WaterPokemon.
     *
     * @return The type of the WaterPokemon.
     */
    string getItsType();

    /**
     * @brief Get the speed of the WaterPokemon.
     *
     * This method overrides the getItsSpeed() method in the Pokemon class
     * to return the float of the speed.
     *
     * @return The speed of the WaterPokemon.
     */
    float getItsSpeed();
};

#endif // WATERPOKEMON_H
