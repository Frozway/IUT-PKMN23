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
    srand (time(NULL));

    SetupMode(itsUserInterface->chooseMode());

    itsUserInterface->topBoard();

    itsPokemonDB->fillARandomTeam(itsTrainer1);
    itsPokemonDB->fillARandomTeam(itsTrainer2);

    Trainer * firstTrainer = isFirstTrainer(itsTrainer1, itsTrainer2)[0];
    Trainer * secondTrainer = isFirstTrainer(itsTrainer1, itsTrainer2)[1];

    itsUserInterface->basicGameDialog(firstTrainer, secondTrainer);
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

array<Trainer*, 2> GameMaker::isFirstTrainer(Trainer * trainer1, Trainer * trainer2)
{
    array<Trainer*, 2> startingTrainers = { nullptr, nullptr };

    if (trainer1->getItsLevel() > trainer2->getItsLevel())
    {
        startingTrainers[0] = trainer1;
        startingTrainers[1] = trainer2;
    }
    else if (trainer2->getItsLevel() > trainer1->getItsLevel())
    {
        startingTrainers[0] = trainer2;
        startingTrainers[1] = trainer1;
    }
    else if (trainer1->getItsTotalCP() > trainer2->getItsTotalCP())
    {
        startingTrainers[0] = trainer1;
        startingTrainers[1] = trainer2;
    }
    else if (trainer2->getItsTotalCP() > trainer1->getItsTotalCP())
    {
        startingTrainers[0] = trainer2;
        startingTrainers[1] = trainer1;
    }
    else
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        int randomIndex = dis(gen);

        startingTrainers[randomIndex] = trainer1;
        startingTrainers[1 - randomIndex] = trainer2;
    }

    return startingTrainers;
}
