/**
* @brief The GrassPokemon class represents a Grass-type Pokemon.
* It inherits from the Pokemon class and adds additional attributes
* specific to Grass-type Pokemon, such as its number of fins and speed.
* @author Thibaut LEFRANCOIS
* @version 0.1
* @date May 2023
* @copyright Thibaut LEFRANCOIS
*/

#ifndef GrassPOKEMON_H
#define GrassPOKEMON_H

#include "pokemon.h"

class GrassPokemon : public Pokemon
{
private:
    float itsSpeed ; /**< The speed of the GrassPokemon. */
    string itsType ; /**< The type of the GrassPokemon. */


public:
    /**
     * @brief Construct a new Grass Pokemon object.
     *
     * @param name The name of the GrassPokemon.
     * @param height The height of the GrassPokemon.
     * @param weight The weight of the GrassPokemon.
     * @param maxHP The max health points of the GrassPokemon.
     * @param currentHP The current health points of the GrassPokemon.
     * @param cp The combat points of the GrassPokemon.
     * @param nbFins The number of fins the GrassPokemon has.
     */
    GrassPokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp);

    /**
     * @brief Return the details of the GrassPokemon.
     *
     * This method overrides the displayPokemon() method in the Pokemon class
     * to include the additional attributes specific to GrassPokemon.
     */
    string displayPokemon() ;

    /**
     * @brief Calculate the damage inflicted on an opponent.
     *
     * This method calculates the damage inflicted on an opponent Pokemon
     * based on the combat points and type advantage of the GrassPokemon.
     *
     * @param anOpponent A pointer to the opponent Pokemon.
     * @return The damage inflicted on the opponent.
     */
    int nbDamage(Pokemon * anOpponent);

    /**
     * @brief Get the type of the GrassPokemon.
     *
     * This method overrides the getItsType() method in the Pokemon class
     * to return the string "Grass", which is the type of GrassPokemon.
     *
     * @return The type of the GrassPokemon.
     */
    string getItsType();

    /**
     * @brief Get the speed of the GrassPokemon.
     *
     * This method overrides the getItsSpeed() method in the Pokemon class
     * to return the float of the speed.
     *
     * @return The speed of the GrassPokemon.
     */
    float getItsSpeed();
};

#endif // GrassPOKEMON_H
