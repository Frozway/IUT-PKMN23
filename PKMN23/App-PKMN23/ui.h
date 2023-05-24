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

//#include <windows.h>
#include <unistd.h>
#include <iomanip>
#include "trainer.h"
#include "pokemon.h"




class UI
{
public:

    UI();

    string Menu();
    void topBoard();
    void bottomBoard();

    void clearScreen();
    void fastClearScreen();
    void pauseText(int time);

    void displayPokemon(Pokemon * pokemon);
    void displayInfoPokemon(Pokemon * pokemon);

    void displayInfoTrainer(Trainer * trainer);
    void displayInfoTrainers(Trainer* trainer1, Trainer* trainer2);
    void displayTeamTrainer(Trainer * trainer);
    void displayTeamsTrainers(Trainer* trainer1, Trainer* trainer2);

    bool isANewPlayer(Trainer* trainer);
    string setupName(Trainer * trainer);

    void displayFight(Trainer * trainer1, Trainer * trainer2);
    void displayFightWinner(Trainer * trainer1, Trainer * trainer2);
    void displayGameWinner(Trainer * winner);

    void printCenteredText(string text);
    void setCenteredTextForAPokemon();
    void setCenteredTextForTeamsColumns();
    void setCenteredTextForInput();

};

#endif // UI_H
