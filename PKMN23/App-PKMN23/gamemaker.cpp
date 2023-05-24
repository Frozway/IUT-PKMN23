#include "gamemaker.h"


GameMaker::GameMaker()
{
    itsUserInterface = new UI();
    itsPokemonDB = new PokemonDataBase();
    itsTrainer1 = new Trainer("Joueur 1");
    itsTrainer2 = new Trainer("Joueur 2");
    itsFirstTrainer = new Trainer("itsFirstTrainer");
    itsSecondTrainer = new Trainer("itsSecondTrainer");
}

GameMaker::~GameMaker()
{
    delete itsUserInterface ;
    delete itsPokemonDB ;
    delete itsTrainer1 ;
    delete itsTrainer2 ;
    delete itsFirstTrainer ;
    delete itsSecondTrainer ;
}

//*********************************************************** JOUER *************************************************************************************//

void GameMaker::Play()
{
    itsUserInterface->clearScreen();

    string mode = itsUserInterface->Menu();

    if(mode == "SOLO VS IA")
    {
        pauseGame(1);
        gameLoopPVAI();
    }
    else if(mode == "MULTIJOUEUR")
    {
        pauseGame(1);
        gameLoopPVP();
    }
    else if(mode == "DEMO")
    {
        pauseGame(1);
        gameLoopAI();
    }
}

void GameMaker::gameLoopPVAI()
{
    srand (time(NULL));

    SetupMode("SOLO VS IA");

    introGame();

    //Si le premier joueur n'est pas une IA (vérifié grâce au nom), alors lui faire choisir son pokémon de départ
    if(itsFirstTrainer->getItsName() == itsTrainer1->getItsName())
    {
        itsUserInterface->displaySetFighter(itsFirstTrainer);
        itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getItsTeam()[0]);
    }
    //Sinon c'est que le joueur 2 n'est pas une IA alors lui faire choisir son pokémon de départ
    else
    {
        itsUserInterface->displaySetFighter(itsSecondTrainer);
        itsFirstTrainer->setFighterPokemon(itsSecondTrainer->getItsTeam()[0]);
    }



    do
    {
        Fight(itsFirstTrainer, itsSecondTrainer);

        //Si le premier joueur est une IA, lui attribuer automatiquement un nouveau pokémon si son pokémon est mort
        if(itsFirstTrainer->getItsName()=="IA-Aron" && itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getNextAlivePokemon());

            //Demander au joueur si il veut changer de pokémon
            if(itsUserInterface->isNewSetFighter(itsSecondTrainer)==true)
            {
                itsUserInterface->displaySetFighter(itsSecondTrainer);
            }
        }

        //Sinon si le premier joueur est le vrai joueur, lui demander de changer de pokémon
        else if(itsFirstTrainer->getItsName()==itsTrainer1->getItsName() && itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsFirstTrainer);
        }

        //Sinon si le deuxième joueur est une IA, lui attribuer automatiquement un nouveau pokémon si son pokémon est mort
        else if(itsSecondTrainer->getItsName()=="IA-Aron" && itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getNextAlivePokemon());

            //Demander au joueur si il veut changer de pokémon
            if(itsUserInterface->isNewSetFighter(itsFirstTrainer)==true)
            {
                itsUserInterface->displaySetFighter(itsFirstTrainer);
            }
        }
        //Sinon si le deuxième joueur est le vrai joueur, lui demander de changer de pokémon
        else if(itsSecondTrainer->getItsName()==itsTrainer1->getItsName() && itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsSecondTrainer);
        }
    }
    while(isGameFinished(itsFirstTrainer, itsSecondTrainer) == false);

    itsUserInterface->displayGameWinner(getWinner(itsFirstTrainer, itsSecondTrainer));

}

void GameMaker::gameLoopPVP()
{
    srand (time(NULL));

    SetupMode("MULTIJOUEUR");

    introGame();

    itsUserInterface->displaySetFighter(itsFirstTrainer);

    itsUserInterface->displaySetFighter(itsSecondTrainer);

    do
    {
        Fight(itsFirstTrainer, itsSecondTrainer);

        if(itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsFirstTrainer);

            if(itsUserInterface->isNewSetFighter(itsSecondTrainer)==true)
            {
                itsUserInterface->displaySetFighter(itsSecondTrainer);
            }
        }
        else if(itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsSecondTrainer);

            if(itsUserInterface->isNewSetFighter(itsFirstTrainer)==true)
            {
                itsUserInterface->displaySetFighter(itsFirstTrainer);
            }
        }
    }
    while(isGameFinished(itsFirstTrainer, itsSecondTrainer) == false);

    itsUserInterface->displayGameWinner(getWinner(itsFirstTrainer, itsSecondTrainer));

}

void GameMaker::gameLoopAI()
{
    srand (time(NULL));

    SetupMode("DEMO");

    introGame();

    //******************************* Lancement des combats ***********************************//

    //Attribution du pokémon aux IA (pour la démo on prendra toujours le premier)
    itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getItsTeam()[0]);
    itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getItsTeam()[0]);

    do
    {
        Fight(itsFirstTrainer, itsSecondTrainer);

        if(itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getNextAlivePokemon());
        }
        else if(itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getNextAlivePokemon());
        }
    }
    while(isGameFinished(itsFirstTrainer, itsSecondTrainer) == false);

    itsUserInterface->displayGameWinner(getWinner(itsFirstTrainer, itsSecondTrainer));

}

void GameMaker::Fight(Trainer * itsFirstTrainer, Trainer * itsSecondTrainer)
{
    int nbAttacksTrainer1 = 0;
    int nbAttacksTrainer2 = 0;

    do
    {
        // Afficher l'état de la bataille entre le premier et le deuxième dresseur
        itsUserInterface->displayFight(itsFirstTrainer, itsSecondTrainer);

        // Le premier dresseur attaque le Pokémon combattant du deuxième dresseur
        itsFirstTrainer->attack(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer, itsSecondTrainer->getFighterPokemon());
        itsFirstTrainer->calculateLevel();
        nbAttacksTrainer1++;

        // Vérifier si la bataille est terminée après l'attaque du premier dresseur
        if (isFightFinished(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer->getFighterPokemon()) == false)
        {
            // Afficher l'état de la bataille entre le deuxième et le premier dresseur
            itsUserInterface->displayFight(itsSecondTrainer, itsFirstTrainer);

            // Le deuxième dresseur attaque le Pokémon combattant du premier dresseur
            itsSecondTrainer->attack(itsSecondTrainer->getFighterPokemon(), itsFirstTrainer, itsFirstTrainer->getFighterPokemon());
            itsSecondTrainer->calculateLevel();
            nbAttacksTrainer2++;

            // Vérifier si la bataille est terminée après l'attaque du deuxième dresseur
            if (isFightFinished(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer->getFighterPokemon()) == true && nbAttacksTrainer2 == 1)
            {
                // Le deuxième dresseur a remporté la bataille en un seul tour, il gagne 3 points et en fait perdre 3 au premier dresseur
                itsSecondTrainer->setItsPoints(itsSecondTrainer->getItsPoints() + 3);
                itsFirstTrainer->setItsPoints(itsFirstTrainer->getItsPoints() - 3);
                break;
            }
        }
        else if(nbAttacksTrainer1 == 1)
        {
            // Le premier dresseur a remporté la bataille en un seul tour, il gagne 3 points et en fait perdre 3 au deuxième dresseur
            itsFirstTrainer->setItsPoints(itsFirstTrainer->getItsPoints() + 3);
            itsSecondTrainer->setItsPoints(itsSecondTrainer->getItsPoints() - 3);
            break;
        }
    } while (isFightFinished(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer->getFighterPokemon()) == false);


    // Afficher le gagnant de la bataille
    itsUserInterface->displayFightWinner(itsFirstTrainer, itsSecondTrainer);

}

void GameMaker::SetupMode(string mode)
{
    itsUserInterface->fastClearScreen();

    if(mode == "SOLO VS IA")
    {
        if(itsUserInterface->isANewPlayer(itsTrainer1) == true)
        {
            itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1));
        }

        itsTrainer2->setItsName("IA-Aron");
    }

    else if(mode == "MULTIJOUEUR")
    {
        if(itsUserInterface->isANewPlayer(itsTrainer1)==true)
        {
            itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1));
        }
        if(itsUserInterface->isANewPlayer(itsTrainer2)==true)
        {
            itsTrainer2->setItsName(itsUserInterface->setupName(itsTrainer2));
        }
    }

    else if(mode == "DEMO")
    {
        itsTrainer1->setItsName("IA-Aron");
        itsTrainer2->setItsName("IA-Nelson");
    }

    itsPokemonDB->fillARandomTeam(itsTrainer1);
    itsPokemonDB->fillARandomTeam(itsTrainer2);

}

void GameMaker::initFirstTrainer(Trainer * trainer1, Trainer * trainer2)
{

    if (trainer1->getItsLevel() > trainer2->getItsLevel())
    {
        itsFirstTrainer = trainer1;
        itsSecondTrainer = trainer2;
    }
    else if (trainer2->getItsLevel() > trainer1->getItsLevel())
    {
        itsFirstTrainer = trainer2;
        itsSecondTrainer = trainer1;
    }
    else if (trainer1->getItsTotalCP() > trainer2->getItsTotalCP())
    {
        itsFirstTrainer = trainer1;
        itsSecondTrainer = trainer2;
    }
    else if (trainer2->getItsTotalCP() > trainer1->getItsTotalCP())
    {
        itsFirstTrainer = trainer2;
        itsSecondTrainer = trainer1;
    }
    else
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        int randomIndex = dis(gen);

        if(randomIndex == 0)
        {
            itsFirstTrainer = trainer1;
            itsSecondTrainer = trainer2;
        }
        else
        {
            itsFirstTrainer = trainer2;
            itsSecondTrainer = trainer1;
        }
    }

    itsFirstTrainer->setItsName("P1 - " + itsFirstTrainer->getItsName());
    itsSecondTrainer->setItsName("P2 - " + itsSecondTrainer->getItsName());
}

void GameMaker::pauseGame(int time)
{
    // Pause pendant le nombre de secondes spécifié
    #ifdef _WIN32
        // Windows
        sleep(time);
    #else
        // UNIX
        sleep(time);
    #endif
}

bool GameMaker::isFightFinished(Pokemon* pokemon1, Pokemon * pokemon2)
{
    if(pokemon1->getItsCurrentHP() == 0 || pokemon2->getItsCurrentHP()==0)
    {
        return true ;
    }
    else return false;
}

Trainer GameMaker::getFightWinner(Trainer * trainer1, Trainer * trainer2)
{
    // Vérifier le vainqueur et le retourner
    if (trainer1->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        return *trainer2;
    }
    else if(trainer2->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        return *trainer1;
    }
}

Trainer * GameMaker::getWinner(Trainer* trainer1, Trainer* trainer2)
{
    if (trainer1->allPokemonsDead() && !trainer2->allPokemonsDead())
    {
        return trainer2; // trainer2 a remporté le combat
    }
    else if (!trainer1->allPokemonsDead() && trainer2->allPokemonsDead())
    {
        return trainer1; // trainer1 a remporté le combat
    }
    else return nullptr ;
}

bool GameMaker::isGameFinished(Trainer* trainer1, Trainer* trainer2)
{
    if(trainer1->allPokemonsDead() == true || trainer2->allPokemonsDead() == true)
    {
        return true;
    }
    else return false;
}

void GameMaker::introGame()
{

    initFirstTrainer(itsTrainer1, itsTrainer2);

    //******************************* Affichage des infos des trainers pour la démo ***********************************//

    itsUserInterface->fastClearScreen();

    itsUserInterface->topBoard();

    itsUserInterface->displayInfoTrainer(itsFirstTrainer);
    itsUserInterface->displayTeamTrainer(itsFirstTrainer);

    itsUserInterface->bottomBoard();

    itsUserInterface->clearScreen();

    itsUserInterface->topBoard();

    itsUserInterface->displayInfoTrainer(itsSecondTrainer);
    itsUserInterface->displayTeamTrainer(itsSecondTrainer);

    itsUserInterface->bottomBoard();
}
