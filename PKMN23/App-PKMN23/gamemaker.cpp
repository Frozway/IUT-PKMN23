#include "gamemaker.h"

GameMaker::GameMaker()
{
    itsUserInterface = new UI();
    itsPokemonDB = new PokemonDataBase();
    itsTrainer1 = new Trainer("Joueur 1");
    itsTrainer2 = new Trainer("Joueur 2");
}

void GameMaker::Play()
{
    SetupMode(itsUserInterface->chooseMode());

}

void GameMaker::SetupMode(string mode)
{
    itsUserInterface->clearScreen();

    if(mode == "SOLO VS IA")
    {
        itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1));
        itsTrainer2->setItsName("IA");
    }

    else if(mode == "MULTIJOUEUR")
    {
        itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1));
        itsTrainer2->setItsName(itsUserInterface->setupName(itsTrainer2));
    }

    else if(mode == "DEMO")
    {
        itsTrainer1->setItsName("IA-1");
        itsTrainer2->setItsName("IA-2");
    }

}
