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

//#include "gamemaker.h"
#include "trainer.h"
#include "pokemon.h"
#include <iomanip>


class UI
{
public:
    UI();
    string chooseMode();
    void displayBoard();
    void clearScreen();
    void displayInfoTrainer(Trainer * trainer);
    void displayInfoPokemon(Pokemon *pokemon);
    void displayPokemonForTeam(Pokemon * pokemon);
    void displayTeamTrainer(Trainer * trainer);
    void basicGameDialog(Trainer * firstTrainer, Trainer * secondTrainer);
    void topBoard();
    void bottomBoard();
    void displaySpace();
    void printCenteredText(string text);
    void printCenteredText(string text, int width);
    void displayInfoTrainers(Trainer * trainer1, Trainer * trainer2);

    string setupName(Trainer * trainer);
};

#endif // UI_H
