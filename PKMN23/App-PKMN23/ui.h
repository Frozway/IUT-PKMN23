#ifndef UI_H
#define UI_H

#define COLOR_RESET  "\033[0m"
#define BOLD         "\033[1m"
#define BLACK_TEXT   "\033[30;1m"
#define RED_TEXT     "\033[31;1m"
#define GREEN_TEXT   "\033[32;1m"
#define YELLOW_TEXT  "\033[33;1m"
#define BLUE_TEXT    "\033[34;1m"
#define MAGENTA_TEXT "\033[35;1m"
#define CYAN_TEXT    "\033[36;1m"
#define WHITE_TEXT   "\033[37;1m"

#include <unistd.h>
#include <iomanip>
#include "trainer.h"
#include "pokemon.h"

/**
 * @brief The UI class handles the user interface of the game.
 */
class UI
{
public:

    /**
     * @brief UI constructor.
     */
    UI();

    /**
     * @brief Menu displays the game menu and returns the selected option.
     * @return The selected menu option.
     */
    string Menu();

    /**
     * @brief topBoard displays the top part of the game board.
     */
    void topBoard();

    /**
     * @brief bottomBoard displays the bottom part of the game board.
     */
    void bottomBoard();

    /**
     * @brief clearScreen clears the console screen.
     */
    void clearScreen();

    /**
     * @brief fastClearScreen clears the console screen quickly.
     */
    void fastClearScreen();

    /**
     * @brief pauseText pauses the display of text for a specified time.
     * @param time The time to pause in milliseconds.
     */
    void pauseText(int time);

    /**
     * @brief displayRules launch the rules on the screen for the user.
     */
    void displayRules();

    /**
     * @brief displayPokemon displays information about a Pokemon.
     * @param pokemon Pointer to the Pokemon to display.
     */
    void displayPokemon(Pokemon * pokemon);

    /**
     * @brief displayInfoPokemon displays detailed information about a Pokemon.
     * @param pokemon Pointer to the Pokemon to display.
     */
    void displayInfoPokemon(Pokemon * pokemon);

    /**
     * @brief displayInfoTrainer displays information about a trainer.
     * @param trainer Pointer to the trainer to display.
     */
    void displayInfoTrainer(Trainer * trainer);

    /**
     * @brief displayInfoTrainers displays information about two trainers side by side.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     */
    void displayInfoTrainers(Trainer* trainer1, Trainer* trainer2);

    /**
     * @brief displayTeamTrainer displays the team of a trainer.
     * @param trainer Pointer to the trainer whose team to display.
     */
    void displayTeamTrainer(Trainer * trainer);

    /**
     * @brief displayTeamsTrainers displays the teams of two trainers side by side.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     */
    void displayTeamsTrainers(Trainer* trainer1, Trainer* trainer2);

    /**
     * @brief isANewPlayer checks if a new player is starting the game.
     * @param trainer Pointer to the trainer to check.
     * @return True if it's a new player, false otherwise.
     */
    bool isANewPlayer(Trainer* trainer);

    /**
     * @brief isNewSetFighter checks if a trainer is setting a new fighter.
     * @param trainer Pointer to the trainer to check.
     * @return True if it's a new set fighter, false otherwise.
     */
    bool isNewSetFighter(Trainer* trainer);

    /**
     * @brief setupName sets up the name of a trainer.
     * @param trainer Pointer to the trainer to set the name for.
     * @return The name entered by the user.
     */
    string setupName(Trainer * trainer);

    /**
     * @brief displaySetFighter displays the set fighter screen for a trainer.
     * @param trainer Pointer to the trainer.
     */
    void displaySetFighter(Trainer * trainer);

    /**
     * @brief displayTransferPokemon displays the transfer Pokemon screen for a trainer.
     * @param trainer Pointer to the trainer.
     * @return The selected Pokemon's index for transfer.
     */
    int displayTransferPokemon(Trainer * trainer);

    /**
     * @brief displayFight displays the fight screen between two trainers.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     */
    void displayFight(Trainer * trainer1, Trainer * trainer2);

    /**
     * @brief displayFightWinner displays the winner of a fight between two trainers.
     * @param trainer1 Pointer to the first trainer.
     * @param trainer2 Pointer to the second trainer.
     */
    void displayFightWinner(Trainer * trainer1, Trainer * trainer2);

    /**
     * @brief displayGameWinner displays the winner of the game.
     * @param winner Pointer to the winning trainer.
     */
    void displayGameWinner(Trainer * winner);

    /**
     * @brief printCenteredText prints a text string centered on the console screen.
     * @param text The text to be centered.
     */
    void printCenteredText(string text);

    /**
     * @brief setCenteredTextForAPokemon sets the console settings for displaying a Pokemon's information centered.
     */
    void setCenteredTextForAPokemon();

    /**
     * @brief setCenteredTextForTeamsColumns sets the console settings for displaying teams' columns centered.
     */
    void setCenteredTextForTeamsColumns();

    /**
     * @brief setCenteredTextForInput sets the console settings for displaying user input centered.
     */
    void setCenteredTextForInput();

    };

    #endif // UI_H
