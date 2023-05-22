#ifndef GAMEMAKER_H
#define GAMEMAKER_H

#include <windows.h>
#include <unistd.h>
#include <random>
#include "ui.h"
#include "pokemon.h"
#include "trainer.h"
#include "pokemondatabase.h"





class GameMaker
{
private:
    UI * itsUserInterface ;
    PokemonDataBase * itsPokemonDB ;
    Trainer * itsTrainer1 ;
    Trainer * itsTrainer2 ;
public:
    GameMaker();
    void Play();
    void Fight(Trainer * firstTrainer, Trainer * secondTrainer);
    void gameLoopPVP();
    void gameLoopPVAI();
    void gameLoopAI();
    void SetupMode(string mode);
    void pauseGame(int time);
    array<Trainer*, 2> isFirstTrainer(Trainer * trainer1, Trainer * trainer2);
};

#endif // GAMEMAKER_H
