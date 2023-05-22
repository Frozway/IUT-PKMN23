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
    system("pause");

    string mode = itsUserInterface->Menu();

    if(mode == "SOLO VS IA")
    {
        gameLoopPVAI();
    }
    else if(mode == "MULTIJOUEUR")
    {
        gameLoopPVP();
    }
    else if(mode == "DEMO")
    {
        gameLoopAI();
    }
}

void GameMaker::gameLoopPVAI()
{
}

void GameMaker::gameLoopPVP()
{
}

void GameMaker::gameLoopAI()
{
    srand (time(NULL));

    SetupMode("DEMO");

    Trainer * firstTrainer = isFirstTrainer(itsTrainer1, itsTrainer2)[0];
    Trainer * secondTrainer = isFirstTrainer(itsTrainer1, itsTrainer2)[1];

    Fight(firstTrainer, secondTrainer);


    //itsUserInterface->basicGameDialog(firstTrainer, secondTrainer);


}

void GameMaker::Fight(Trainer * firstTrainer, Trainer * secondTrainer)
{
    firstTrainer->setFighterPokemon(firstTrainer->getItsTeam()[1]);
    secondTrainer->setFighterPokemon(secondTrainer->getItsTeam()[1]);
    //itsUserInterface->displayTeamTrainer(firstTrainer);



    itsUserInterface->displayFight(firstTrainer, secondTrainer);

//    firstTrainer->attack(firstTrainer->getFighterPokemon(), secondTrainer, secondTrainer->getFighterPokemon()) ;
//    secondTrainer->attack(secondTrainer->getFighterPokemon(), firstTrainer, firstTrainer->getFighterPokemon());

//    itsUserInterface->displayFight(firstTrainer->getFighterPokemon(), secondTrainer->getFighterPokemon());

}










void GameMaker::SetupMode(string mode)
{
    itsUserInterface->clearScreen();

    if(mode == "SOLO VS IA")
    {
        if(itsUserInterface->isANewPlayer(itsTrainer1) == true)
        {
            itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1));
        }

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
        itsPokemonDB->fillARandomTeam(itsTrainer1);
        itsPokemonDB->fillARandomTeam(itsTrainer2);

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


