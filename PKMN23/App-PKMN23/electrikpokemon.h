#ifndef ELECTRIKPOKEMON_H
#define ELECTRIKPOKEMON_H

#include "pokemon.h"

/**
 * @brief The ElectrikPokemon class represents a Electrik-type Pokemon.
 *
 * It inherits from the Pokemon class and adds additional attributes
 * specific to Electrik-type Pokemon, such as its number of fins and speed.
 */
class ElectrikPokemon : public Pokemon
{
private:
    int itsNbLegs ; /**< The number of fins the ElectrikPokemon has. */
    int itsNbWings ; /**< The number of wings the ElectrikPokemon has. */
    int itsIntensity ;  /**< The electrical intensity the ElectrikPokemon has. */
    float itsSpeed ; /**< The speed of the ElectrikPokemon. */

public:
    /**
     * @brief Construct a new Electrik Pokemon object.
     *
     * @param name The name of the ElectrikPokemon.
     * @param height The height of the ElectrikPokemon.
     * @param weight The weight of the ElectrikPokemon.
     * @param hp The health points of the ElectrikPokemon.
     * @param cp The combat points of the ElectrikPokemon.
     * @param nbFins The number of fins the ElectrikPokemon has.
     */
    ElectrikPokemon(string name, float height, float weight, int hp, int cp, int nbLegs, int nbWings, int intensity);

    /**
     * @brief Display the details of the ElectrikPokemon.
     *
     * This method overrides the displayPokemon() method in the Pokemon class
     * to include the additional attributes specific to ElectrikPokemon.
     */
    void displayPokemon() ;

    /**
     * @brief Calculate the damage inflicted on an opponent.
     *
     * This method calculates the damage inflicted on an opponent Pokemon
     * based on the combat points and type advantage of the ElectrikPokemon.
     *
     * @param anOpponent A pointer to the opponent Pokemon.
     * @return The damage inflicted on the opponent.
     */
    int nbDamage(Pokemon * anOpponent);

    /**
     * @brief Attack an opponent Pokemon.
     *
     * This method simulates an attack by the current ElectrikPokemon on an opponent
     * Pokemon by reducing the opponent's health points based on the damage inflicted.
     *
     * @param currentPokemon A pointer to the current ElectrikPokemon.
     * @param anOpponent A pointer to the opponent Pokemon.
     */
    //void attack(Pokemon * currentPokemon, Pokemon * anOpponent);

    /**
     * @brief Get the type of the ElectrikPokemon.
     *
     * This method overrides the getItsType() method in the Pokemon class
     * to return the string "Electrik", which is the type of ElectrikPokemon.
     *
     * @return The type of the ElectrikPokemon.
     */
    string getItsType();
};

#endif // ElectrikPOKEMON_H
