#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std ;


/**
 * @brief Classe représentant un Pokémon
 *
 * Cette classe abstraire permet de définir les points commun à tous les types de Pokémon.
 * Elle contient des méthodes virtuelles pures qui doivent être implémentées
 * par les classes filles pour calculer des dégâts et effectuer des attaques.
 */
class Pokemon
{
protected:
    string itsName ; /**< Le nom du Pokémon */
    float itsHeight ; /**< La taille du Pokémon en mètres */
    float itsWeight ; /**< Le poids du Pokémon en kilogrammes */
    int itsHP ; /**< Le nombre de points de vie du Pokémon */
    int itsCP ; /**< Le nombre de points de combat du Pokémon */

public:
    /**
     * @brief Constructeur de la classe Pokemon
     *
     * @param name Le nom du Pokémon
     * @param height La taille du Pokémon en mètres
     * @param weight Le poids du Pokémon en kilogrammes
     * @param hp Le nombre de points de vie du Pokémon
     * @param cp Le nombre de points de combat du Pokémon
     */
    Pokemon(string name, float height, float weight, int hp, int cp);

    /**
     * @brief Destructeur virtuel de la classe Pokemon
     */
    virtual ~Pokemon() {}

    /**
     * @brief Méthode virtuelle pure affichant les informations du Pokémon
     *
     * Cette méthode doit être implémentée par les classes filles pour afficher
     * les informations spécifiques à chaque type de Pokémon.
     */
    virtual void displayPokemon() = 0;

    /**
     * @brief Méthode virtuelle pure retournant le type du Pokémon
     *
     * Cette méthode doit être implémentée par les classes filles pour retourner
     * le type spécifique à chaque type de Pokémon.
     *
     * @return Le type du Pokémon
     */
    virtual string getItsType() = 0;

    /**
     * @brief Méthode virtuelle pure calculant les dégâts infligés par le Pokémon
     *
     * Cette méthode doit être implémentée par les classes filles pour calculer et retourner
     * le nombre de dégâts qui seront infligés par le Pokémon selon le type de son adversaire.
     */
    virtual int nbDamage(Pokemon * anOpponent) = 0;

    /**
     * @brief Méthode virtuelle pure effectuant une attaque contre un adversaire
     *
     * Cette méthode doit être implémentée par les classes filles pour effectuer
     * une attaque spécifique à chaque type de Pokémon contre un adversaire.
     *
     * @param anOpponent Le Pokémon adversaire à attaquer
     */
    virtual void attack(Pokemon * anOpponent) = 0 ;

    int getItsHP() const;
    int getItsCP() const;
    void setItsHP(int newItsHP);
};

#endif // POKEMON_H
