#ifndef GAMEMAKER_H
#define GAMEMAKER_H

#include <random>
#include "ui.h"
#include "pokemon.h"
#include "trainer.h"
#include "pokemondatabase.h"

/**
 * @brief The GameMaker class manages the game flow and interactions between trainers, Pokemon, and the user interface.
 */
class GameMaker
{
private:
    UI * itsUserInterface ; /**< The user interface object */
    PokemonDataBase * itsPokemonDB ; /**< The Pokemon database object */
    Trainer * itsTrainer1 ; /**< Pointer to the first trainer */
    Trainer * itsTrainer2 ; /**< Pointer to the second trainer */
    Trainer * itsFirstTrainer; /**< Pointer to the first trainer in a fight */
    Trainer * itsSecondTrainer; /**< Pointer to the second trainer in a fight */

public:
    /**
     * @brief GameMaker constructor.
     */
    GameMaker();

    /**
     * @brief GameMaker destructor.
     */
    ~GameMaker();

    /**
     * @brief Play starts the game and manages the game loop.
     */
    void Play();

    /**
     * @brief gameLoopPVAI manages the game loop for player vs. AI mode.
     */
    void gameLoopPVAI();

    /**
     * @brief gameLoopPVP manages the game loop for player vs. player mode.
     */
    void gameLoopPVP();

    /**
     * @brief gameLoopAI manages the game loop for AI vs. AI mode.
     */
    void gameLoopAI();

    /**
     * @brief introGame displays the game intro.
     */
    void introGame();

    /**
     * @brief setupMode sets up the game mode (PvP, PvAI, AIvAI).
     * @param mode The game mode.
     */
    void setupMode(string mode);

    /**
     * @brief initFirstSecondTrainer initializes the first and second trainers for a fight.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     */
    void initFirstSecondTrainer(Trainer * trainer1, Trainer * trainer2);

    /**
     * @brief Fight simulates a fight between two trainers.
     * @param itsFirstTrainer Pointer to the first trainer.
     * @param itsSecondTrainer Pointer to the second trainer.
     */
    void Fight(Trainer * itsFirstTrainer, Trainer * itsSecondTrainer);

    /**
     * @brief pauseGame pauses the game for a specified time.
     * @param time The time to pause in milliseconds.
     */
    void pauseGame(int time);

    /**
     * @brief isFightFinished checks if a fight between two Pokemon is finished.
     * @param pokemon1 Pointer to the first Pokemon.
     * @param pokemon2 Pointer to the second Pokemon.
     * @return True if the fight is finished, false otherwise.
     */
    bool isFightFinished(Pokemon* pokemon1, Pokemon * pokemon2);

    /**
     * @brief isGameFinished checks if a game between two trainers is finished.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     * @return True if the game is finished, false otherwise.
     */
    bool isGameFinished(Trainer* trainer1, Trainer* trainer2);

    /**
     * @brief getFightWinner determines the winner of a fight between two trainers.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     * @return The winner trainer.
     */
    Trainer getFightWinner(Trainer * trainer1, Trainer * trainer2);

    /**
     * @brief getWinner determines the winner of a game between two trainers.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     * @return The winner trainer.
     */
    Trainer * getWinner(Trainer* trainer1, Trainer* trainer2);

    /**
     * @brief transferPokemon transfers a Pokemon from one trainer to another.
     * @param trainer Pointer to the trainer who transfers the Pokemon.
     * @param pokemonToTransfer Pointer to the Pokemon to be transferred.
     */
    void transferPokemon(Trainer * trainer, Pokemon* pokemonToTransfer);

    /**
     * @brief Getter pour l'interface utilisateur.
     * @return L'interface utilisateur associée à cette instance de GameMaker.
     */
    UI* getItsUserInterface() const;

    /**
     * @brief Setter pour l'interface utilisateur.
     * @param newItsUserInterface Le nouvel objet UI à associer à cette instance de GameMaker.
     */
    void setItsUserInterface(UI* newItsUserInterface);

    /**
     * @brief Getter pour la base de données de Pokémon.
     * @return La base de données de Pokémon associée à cette instance de GameMaker.
     */
    PokemonDataBase* getItsPokemonDB() const;

    /**
     * @brief Setter pour la base de données de Pokémon.
     * @param newItsPokemonDB Le nouvel objet PokemonDataBase à associer à cette instance de GameMaker.
     */
    void setItsPokemonDB(PokemonDataBase* newItsPokemonDB);

    /**
     * @brief Getter pour le premier dresseur.
     * @return Le premier dresseur associé à cette instance de GameMaker.
     */
    Trainer* getItsTrainer1() const;

    /**
     * @brief Setter pour le premier dresseur.
     * @param newItsTrainer1 Le nouvel objet Trainer à associer en tant que premier dresseur dans cette instance de GameMaker.
     */
    void setItsTrainer1(Trainer* newItsTrainer1);

    /**
     * @brief Getter pour le deuxième dresseur.
     * @return Le deuxième dresseur associé à cette instance de GameMaker.
     */
    Trainer* getItsTrainer2() const;

    /**
     * @brief Setter pour le deuxième dresseur.
     * @param newItsTrainer2 Le nouvel objet Trainer à associer en tant que deuxième dresseur dans cette instance de GameMaker.
     */
    void setItsTrainer2(Trainer* newItsTrainer2);

    /**
     * @brief Getter pour le premier dresseur dans une bataille.
     * @return Le premier dresseur associé à cette instance de GameMaker lors d'une bataille.
     */
    Trainer* getItsFirstTrainer() const;

    /**
     * @brief Setter pour le premier dresseur dans une bataille.
     * @param newItsFirstTrainer Le nouvel objet Trainer à associer en tant que premier dresseur lors d'une bataille dans cette instance de GameMaker.
     */
    void setItsFirstTrainer(Trainer* newItsFirstTrainer);

    /**
     * @brief Getter pour le deuxième dresseur dans une bataille.
     * @return Le deuxième dresseur associé à cette instance de GameMaker lors d'une bataille.
     */
    Trainer* getItsSecondTrainer() const;

    /**
     * @brief Setter pour le deuxième dresseur dans une bataille.
     * @param newItsSecondTrainer Le nouvel objet Trainer à associer en tant que deuxième dresseur lors d'une bataille dans cette instance de GameMaker.
     */
    void setItsSecondTrainer(Trainer* newItsSecondTrainer);

};

#endif // GAMEMAKER_H
