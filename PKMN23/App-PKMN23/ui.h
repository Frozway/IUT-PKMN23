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

class UI
{
public:
    UI();
    void displayMenu();
    void displayBoard();
    void clearScreen();


    void displayTrainer(Trainer * trainer);
    void displayPokemon(Pokemon *pokemon);
    void displayTeamTrainer(Trainer * trainer);
};

#endif // UI_H
