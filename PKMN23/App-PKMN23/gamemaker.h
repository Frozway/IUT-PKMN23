#ifndef GAMEMAKER_H
#define GAMEMAKER_H

#include "pokemon.h"
#include "trainer.h"
#include "ui.h"
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
    void SetupMode(string mode);
};

#endif // GAMEMAKER_H
