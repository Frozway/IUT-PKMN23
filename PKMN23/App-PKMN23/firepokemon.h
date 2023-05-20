/**
* @brief The FirePokemon class represents a Fire-type Pokemon.
* It inherits from the Pokemon class and adds additional attributes
* specific to Fire-type Pokemon, such as its number of fins and speed.
* @author Thibaut LEFRANCOIS
* @version 0.1
* @date May 2023
* @copyright Thibaut LEFRANCOIS
*/

#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H


#include "pokemon.h"

class FirePokemon : public Pokemon
{
private:
    int itsNbLegs ; /**< The number of fins the FirePokemon has. */
    float itsSpeed ; /**< The speed of the FirePokemon. */
    string itsType; /**< The type of the FirePokemon. */

public:
    /**
     * @brief Construct a new Fire Pokemon object.
     *
     * @param name The name of the FirePokemon.
     * @param height The height of the FirePokemon.
     * @param weight The weight of the FirePokemon.
     * @param maxHP The max health points of the FirePokemon.
     * @param currentHP The current health points of the FirePokemon.
     * @param cp The combat points of the FirePokemon.
     * @param nbFins The number of fins the FirePokemon has.
     */
    FirePokemon(string name, float height, float weight, unsigned int maxHP, int currentHP, unsigned int cp, int nbLegs);

    /**
     * @brief Return the details of the FirePokemon.
     *
     * This method overrides the displayPokemon() method in the Pokemon class
     * to include the additional attributes specific to FirePokemon.
     */
    string displayPokemon() ;

    /**
     * @brief Calculate the damage inflicted on an opponent.
     *
     * This method calculates the damage inflicted on an opponent Pokemon
     * based on the combat points and type advantage of the FirePokemon.
     *
     * @param anOpponent A pointer to the opponent Pokemon.
     * @return The damage inflicted on the opponent.
     */
    int nbDamage(Pokemon * anOpponent);

    /**
     * @brief Get the type of the FirePokemon.
     *
     * This method overrides the getItsType() method in the Pokemon class
     * to return the string "Fire", which is the type of FirePokemon.
     *
     * @return The type of the FirePokemon.
     */
    string getItsType();

    /**
     * @brief Get the speed of the FirePokemon.
     *
     * This method overrides the getItsSpeed() method in the Pokemon class
     * to return the float of the speed.
     *
     * @return The speed of the FirePokemon.
     */
    float getItsSpeed();
};

#endif // FIREPOKEMON_H
