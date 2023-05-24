#ifndef GAMEMAKER_H
#define GAMEMAKER_H

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
    Trainer * itsFirstTrainer;
    Trainer * itsSecondTrainer;

public:
    GameMaker();
    ~GameMaker();
    void Play();
    void Fight(Trainer * firstTrainer, Trainer * secondTrainer);
    void gameLoopPVP();
    void gameLoopPVAI();
    void gameLoopAI();
    void pauseGame(int time);
    bool isFightFinished(Pokemon * pokemon1, Pokemon * pokemon2);
    bool isGameFinished(Trainer* trainer1, Trainer* trainer2);
    void SetupMode(string mode);
    void initFirstTrainer(Trainer * trainer1, Trainer * trainer2);
    Trainer getFightWinner(Trainer * trainer1, Trainer * trainer2);
    Trainer * getWinner(Trainer* trainer1, Trainer* trainer2);
    void introGame();

};

#endif // GAMEMAKER_H
