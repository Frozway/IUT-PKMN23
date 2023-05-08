#ifndef GrassPOKEMON_H
#define GrassPOKEMON_H

#include "pokemon.h"

/**
 * @brief The GrassPokemon class represents a Grass-type Pokemon.
 *
 * It inherits from the Pokemon class and adds additional attributes
 * specific to Grass-type Pokemon, such as its number of fins and speed.
 */
class GrassPokemon : public Pokemon
{
private:
    float itsSpeed ; /**< The speed of the GrassPokemon. */

public:
    /**
     * @brief Construct a new Grass Pokemon object.
     *
     * @param name The name of the GrassPokemon.
     * @param height The height of the GrassPokemon.
     * @param weight The weight of the GrassPokemon.
     * @param hp The health points of the GrassPokemon.
     * @param cp The combat points of the GrassPokemon.
     * @param nbFins The number of fins the GrassPokemon has.
     */
    GrassPokemon(string name, float height, float weight, int hp, int cp);

    /**
     * @brief Display the details of the GrassPokemon.
     *
     * This method overrides the displayPokemon() method in the Pokemon class
     * to include the additional attributes specific to GrassPokemon.
     */
    void displayPokemon() ;

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
     * @brief Attack an opponent Pokemon.
     *
     * This method simulates an attack by the current GrassPokemon on an opponent
     * Pokemon by reducing the opponent's health points based on the damage inflicted.
     *
     * @param currentPokemon A pointer to the current GrassPokemon.
     * @param anOpponent A pointer to the opponent Pokemon.
     */
    //void attack(Pokemon * currentPokemon, Pokemon * anOpponent);

    /**
     * @brief Get the type of the GrassPokemon.
     *
     * This method overrides the getItsType() method in the Pokemon class
     * to return the string "Grass", which is the type of GrassPokemon.
     *
     * @return The type of the GrassPokemon.
     */
    string getItsType();
};

#endif // GrassPOKEMON_H
