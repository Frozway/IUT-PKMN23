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
    srand (time(NULL)); // Initialise la graine du générateur de nombres aléatoires

    setupMode("SOLO VS IA"); // Configure le mode de jeu en solo contre l'IA

    introGame(); // Affiche l'introduction du jeu

    // Le vrai joueur est initialement itsTrainer1, donc il choisit son Pokémon en premier
    if (itsFirstTrainer->getItsName() == itsTrainer1->getItsName())
    {
        itsUserInterface->displaySetFighter(itsFirstTrainer); // Affiche l'écran de sélection du premier combattant pour le vrai joueur
        itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getItsTeam()[0]); // L'IA sélectionne automatiquement son premier Pokémon
    }
    else
    {
        itsUserInterface->displaySetFighter(itsSecondTrainer); // Affiche l'écran de sélection du premier combattant pour l'IA
        itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getItsTeam()[0]); // Le vrai joueur sélectionne automatiquement son premier Pokémon
    }

    do
    {
        Fight(itsFirstTrainer, itsSecondTrainer); // Lance un combat entre le vrai joueur et l'IA

        if (isGameFinished(itsFirstTrainer, itsSecondTrainer) == true)
        {
            break; // Si le jeu est terminé, sort de la boucle
        }

        // Si le premier joueur est une IA et que son Pokémon est mort, lui attribuer automatiquement un nouveau Pokémon
        if (itsFirstTrainer->getItsName() == "IA-Aron" && itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getNextAlivePokemon());

            // Demande au vrai joueur s'il veut changer de Pokémon
            if (itsUserInterface->isNewSetFighter(itsSecondTrainer) == true)
            {
                itsUserInterface->displaySetFighter(itsSecondTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le vrai joueur
            }
        }
        // Si le premier joueur est le vrai joueur et que son Pokémon est mort, lui demande de changer de Pokémon
        else if (itsFirstTrainer->getItsName() == itsTrainer1->getItsName() && itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsFirstTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le vrai joueur
        }
        // Si le deuxième joueur est une IA et que son Pokémon est mort, lui attribuer automatiquement un nouveau Pokémon
        else if (itsSecondTrainer->getItsName() == "IA-Aron" && itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getNextAlivePokemon());

            // Demande au vrai joueur s'il veut changer de Pokémon
            if (itsUserInterface->isNewSetFighter(itsFirstTrainer) == true)
            {
                itsUserInterface->displaySetFighter(itsFirstTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le vrai joueur
            }
        }
        // Si le deuxième joueur est le vrai joueur et que son Pokémon est mort, lui demande de changer de Pokémon
        else if (itsSecondTrainer->getItsName() == itsTrainer1->getItsName() && itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsSecondTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le vrai joueur
        }
    }
    while (isGameFinished(itsFirstTrainer, itsSecondTrainer) == false); // Continue la boucle tant que le jeu n'est pas terminé

    itsUserInterface->displayGameWinner(getWinner(itsFirstTrainer, itsSecondTrainer)); // Affiche le vainqueur du jeu
}

void GameMaker::gameLoopPVP()
{
    srand (time(NULL)); // Initialise la graine du générateur de nombres aléatoires

    setupMode("MULTIJOUEUR"); // Configure le mode de jeu en mode multijoueur

    introGame(); // Affiche l'introduction du jeu

    itsUserInterface->displaySetFighter(itsFirstTrainer); // Affiche l'écran de sélection du premier combattant pour le premier joueur

    itsUserInterface->displaySetFighter(itsSecondTrainer); // Affiche l'écran de sélection du premier combattant pour le deuxième joueur

    do
    {
        Fight(itsFirstTrainer, itsSecondTrainer); // Lance un combat entre les deux joueurs

        if(isGameFinished(itsFirstTrainer, itsSecondTrainer)==true)
        {
            break; // Si le jeu est terminé, sort de la boucle
        }

        if(itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsFirstTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le premier joueur

            if(itsUserInterface->isNewSetFighter(itsSecondTrainer)==true)
            {
                itsUserInterface->displaySetFighter(itsSecondTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le deuxième joueur
            }
        }
        else if(itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsUserInterface->displaySetFighter(itsSecondTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le deuxième joueur

            if(itsUserInterface->isNewSetFighter(itsFirstTrainer)==true)
            {
                itsUserInterface->displaySetFighter(itsFirstTrainer); // Affiche l'écran de sélection d'un nouveau combattant pour le premier joueur
            }
        }
    }
    while(isGameFinished(itsFirstTrainer, itsSecondTrainer) == false); // Continue la boucle tant que le jeu n'est pas terminé

    itsUserInterface->displayGameWinner(getWinner(itsFirstTrainer, itsSecondTrainer)); // Affiche le vainqueur du jeu
}

void GameMaker::gameLoopAI()
{
    srand (time(NULL)); // Initialise la graine du générateur de nombres aléatoires

    setupMode("DEMO"); // Configure le mode de jeu en mode démonstration

    introGame(); // Affiche l'introduction du jeu

    //******************************* Lancement des combats ***********************************//

    // Attribution du premier Pokémon aux IA (pour la démonstration, on choisit toujours le premier Pokémon)
    itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getItsTeam()[0]);
    itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getItsTeam()[0]);

    do
    {
        Fight(itsFirstTrainer, itsSecondTrainer); // Lance un combat entre les deux IA

        if (isGameFinished(itsFirstTrainer, itsSecondTrainer) == true)
        {
            break; // Si le jeu est terminé, sort de la boucle
        }

        // Si le Pokémon du premier joueur est mort, attribuer automatiquement le prochain Pokémon vivant
        if (itsFirstTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsFirstTrainer->setFighterPokemon(itsFirstTrainer->getNextAlivePokemon());
        }
        // Sinon, si le Pokémon du deuxième joueur est mort, attribuer automatiquement le prochain Pokémon vivant
        else if (itsSecondTrainer->getFighterPokemon()->getItsCurrentHP() == 0)
        {
            itsSecondTrainer->setFighterPokemon(itsSecondTrainer->getNextAlivePokemon());
        }
    }
    while (isGameFinished(itsFirstTrainer, itsSecondTrainer) == false); // Continue la boucle tant que le jeu n'est pas terminé

    itsUserInterface->displayGameWinner(getWinner(itsFirstTrainer, itsSecondTrainer)); // Affiche le vainqueur du jeu
}


//*********************************************************** Initialisation *************************************************************************************//

void GameMaker::introGame()
{
    initFirstSecondTrainer(itsTrainer1, itsTrainer2); // Initialise les joueurs (trainers)

    itsUserInterface->fastClearScreen(); // Efface rapidement l'écran

    itsUserInterface->topBoard(); // Affiche le tableau supérieur

    itsUserInterface->displayInfoTrainer(itsFirstTrainer); // Affiche les informations du premier joueur (trainer)
    itsUserInterface->displayTeamTrainer(itsFirstTrainer); // Affiche l'équipe du premier joueur (trainer)

    if (itsFirstTrainer->getItsName() != "IA-Aron" && itsFirstTrainer->getItsName() != "IA-Nelson")
    {
        // Vérifie si le joueur a suffisamment de points ou un niveau supérieur à 1 pour effectuer un transfert de Pokémon
        if (itsFirstTrainer->getItsPoints() >= 2 || itsFirstTrainer->getItsLevel() > 1)
        {
            int indexPokemonToTransfer = itsUserInterface->displayTransferPokemon(itsFirstTrainer); // Affiche le menu de transfert de Pokémon
            if (indexPokemonToTransfer != 0)
            {
                Pokemon *pokemonToTransfer = itsFirstTrainer->getItsTeam()[indexPokemonToTransfer-1]; // Sélectionne le Pokémon à transférer
                transferPokemon(itsFirstTrainer, pokemonToTransfer); // Effectue le transfert du Pokémon
                itsUserInterface->displayTeamTrainer(itsFirstTrainer); // Affiche l'équipe mise à jour du premier joueur (trainer)
                itsUserInterface->bottomBoard(); // Affiche le tableau inférieur
            }
        }
    }



    itsUserInterface->clearScreen(); // Efface l'écran

    itsUserInterface->topBoard(); // Affiche le tableau supérieur

    itsUserInterface->displayInfoTrainer(itsSecondTrainer); // Affiche les informations du deuxième joueur (trainer)
    itsUserInterface->displayTeamTrainer(itsSecondTrainer); // Affiche l'équipe du deuxième joueur (trainer)

    if (itsSecondTrainer->getItsName() != "IA-Aron" && itsSecondTrainer->getItsName() != "IA-Nelson")
    {
        // Vérifie si le joueur a suffisamment de points ou un niveau supérieur à 1 pour effectuer un transfert de Pokémon
        if (itsSecondTrainer->getItsPoints() >= 2 || itsSecondTrainer->getItsLevel() > 1)
        {
            int indexPokemonToTransfer = itsUserInterface->displayTransferPokemon(itsSecondTrainer); // Affiche le menu de transfert de Pokémon
            if (indexPokemonToTransfer != 0)
            {
                Pokemon *pokemonToTransfer = itsSecondTrainer->getItsTeam()[indexPokemonToTransfer-1]; // Sélectionne le Pokémon à transférer
                transferPokemon(itsSecondTrainer, pokemonToTransfer); // Effectue le transfert du Pokémon
                itsUserInterface->displayTeamTrainer(itsSecondTrainer); // Affiche l'équipe mise à jour du deuxième joueur (trainer)
                itsUserInterface->bottomBoard(); // Affiche le tableau inférieur
            }
        }
    }

    itsUserInterface->bottomBoard(); // Affiche le tableau inférieur
}

void GameMaker::setupMode(string mode)
{
    itsUserInterface->fastClearScreen(); // Efface rapidement l'écran

    if (mode == "SOLO VS IA")
    {
        if (itsUserInterface->isANewPlayer(itsTrainer1) == true)
        {
            itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1)); // Configure le nom du premier joueur (trainer) s'il est nouveau
        }

        itsTrainer2->setItsName("IA-Aron"); // Configure le nom du deuxième joueur (trainer) comme IA-Aron
    }
    else if (mode == "MULTIJOUEUR")
    {
        if (itsUserInterface->isANewPlayer(itsTrainer1) == true)
        {
            itsTrainer1->setItsName(itsUserInterface->setupName(itsTrainer1)); // Configure le nom du premier joueur (trainer) s'il est nouveau
        }
        if (itsUserInterface->isANewPlayer(itsTrainer2) == true)
        {
            itsTrainer2->setItsName(itsUserInterface->setupName(itsTrainer2)); // Configure le nom du deuxième joueur (trainer) s'il est nouveau
        }
    }
    else if (mode == "DEMO")
    {
        itsTrainer1->setItsName("IA-Aron"); // Configure le nom du premier joueur (trainer) comme IA-Aron
        itsTrainer2->setItsName("IA-Nelson"); // Configure le nom du deuxième joueur (trainer) comme IA-Nelson
    }

    itsPokemonDB->fillARandomTeam(itsTrainer1); // Remplit l'équipe du premier joueur (trainer) avec des Pokémon aléatoires
    itsPokemonDB->fillARandomTeam(itsTrainer2); // Remplit l'équipe du deuxième joueur (trainer) avec des Pokémon aléatoires
}

void GameMaker::initFirstSecondTrainer(Trainer *trainer1, Trainer *trainer2)
{
    // Comparaison des niveaux des deux entraîneurs
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
    // Si les niveaux sont égaux, on compare les points de combat totaux (total CP)
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
    // Si les niveaux et les points de combat totaux sont égaux, on choisit au hasard
    else
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        int randomIndex = dis(gen);

        if (randomIndex == 0)
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

    // Mise à jour des noms des entraîneurs pour correspondre aux sélectionnés
    itsFirstTrainer->setItsName(itsFirstTrainer->getItsName());
    itsSecondTrainer->setItsName(itsSecondTrainer->getItsName());
}

//*********************************************************** Gestion de Partie *************************************************************************************//

void GameMaker::Fight(Trainer* itsFirstTrainer, Trainer* itsSecondTrainer)
{
    int nbAttacksTrainer1 = 0;
    int nbAttacksTrainer2 = 0;

    do
    {
        // Afficher l'état actuel de la bataille entre le premier et le deuxième dresseur
        itsUserInterface->displayFight(itsFirstTrainer, itsSecondTrainer);

        // Le premier dresseur attaque le Pokémon combattant du deuxième dresseur
        itsFirstTrainer->attack(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer, itsSecondTrainer->getFighterPokemon());
        itsFirstTrainer->calculateLevel();
        nbAttacksTrainer1++;

        // Vérifier si la bataille est terminée après l'attaque du premier dresseur
        if (isFightFinished(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer->getFighterPokemon()) == false)
        {
            // Afficher l'état actuel de la bataille entre le deuxième et le premier dresseur
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
                itsSecondTrainer->calculateLevel();
                if (itsFirstTrainer->getItsPoints() >= 3)
                {
                    itsFirstTrainer->setItsPoints(itsFirstTrainer->getItsPoints() - 3);
                }

                break;
            }
        }
        else if (nbAttacksTrainer1 == 1)
        {
            // Le premier dresseur a remporté la bataille en un seul tour, il gagne 3 points et en fait perdre 3 au deuxième dresseur
            itsFirstTrainer->setItsPoints(itsFirstTrainer->getItsPoints() + 3);
            itsFirstTrainer->calculateLevel();
            if (itsSecondTrainer->getItsPoints() >= 3)
            {
                itsSecondTrainer->setItsPoints(itsSecondTrainer->getItsPoints() - 3);
            }

            break;
        }
    } while (isFightFinished(itsFirstTrainer->getFighterPokemon(), itsSecondTrainer->getFighterPokemon()) == false);

    // Afficher le gagnant de la bataille
    itsUserInterface->displayFightWinner(itsFirstTrainer, itsSecondTrainer);
}

bool GameMaker::isFightFinished(Pokemon* pokemon1, Pokemon* pokemon2)
{
    // Vérifier si l'un des Pokémon n'a plus de points de vie
    if (pokemon1->getItsCurrentHP() == 0 || pokemon2->getItsCurrentHP() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GameMaker::isGameFinished(Trainer* trainer1, Trainer* trainer2)
{
    // Vérifier si l'un des dresseurs n'a plus de Pokémon en vie
    if (trainer1->allPokemonsDead() == true || trainer2->allPokemonsDead() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Trainer GameMaker::getFightWinner(Trainer* trainer1, Trainer* trainer2)
{
    // Vérifier quel dresseur a remporté le combat et le retourner
    if (trainer1->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        return *trainer2;
    }
    else if (trainer2->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        return *trainer1;
    }
    // Si aucun des Pokémon n'est vainqueur, le résultat n'est pas défini
    // Il peut être préférable de retourner un pointeur nul ou de lever une exception dans ce cas
}

Trainer* GameMaker::getWinner(Trainer* trainer1, Trainer* trainer2)
{
    // Vérifier quel dresseur a remporté la partie et le retourner
    if (trainer1->allPokemonsDead() && !trainer2->allPokemonsDead())
    {
        return trainer2; // trainer2 a remporté la partie
    }
    else if (!trainer1->allPokemonsDead() && trainer2->allPokemonsDead())
    {
        return trainer1; // trainer1 a remporté la partie
    }
    else
    {
        return nullptr; // Aucun dresseur n'a remporté la partie ou il y a une égalité
    }
}

void GameMaker::pauseGame(int time)
{
    sleep(time);
}

void GameMaker::transferPokemon(Trainer* trainer, Pokemon* pokemonToTransfer)
{
    // Transférer un Pokémon du dresseur et en choisir un nouveau aléatoirement
    trainer->removePokemon(pokemonToTransfer);
    itsPokemonDB->pickARandomPokemon(trainer);
    trainer->setItsPoints(trainer->getItsPoints() - 2);
    trainer->calculateLevel();
}

//*********************************************************** Getter et Setter *************************************************************************************//

UI *GameMaker::getItsUserInterface() const
{
    return itsUserInterface;
}

void GameMaker::setItsUserInterface(UI *newItsUserInterface)
{
    itsUserInterface = newItsUserInterface;
}

PokemonDataBase *GameMaker::getItsPokemonDB() const
{
    return itsPokemonDB;
}

void GameMaker::setItsPokemonDB(PokemonDataBase *newItsPokemonDB)
{
    itsPokemonDB = newItsPokemonDB;
}

Trainer *GameMaker::getItsTrainer1() const
{
    return itsTrainer1;
}

void GameMaker::setItsTrainer1(Trainer *newItsTrainer1)
{
    itsTrainer1 = newItsTrainer1;
}

Trainer *GameMaker::getItsTrainer2() const
{
    return itsTrainer2;
}

void GameMaker::setItsTrainer2(Trainer *newItsTrainer2)
{
    itsTrainer2 = newItsTrainer2;
}

Trainer *GameMaker::getItsFirstTrainer() const
{
    return itsFirstTrainer;
}

void GameMaker::setItsFirstTrainer(Trainer *newItsFirstTrainer)
{
    itsFirstTrainer = newItsFirstTrainer;
}

Trainer *GameMaker::getItsSecondTrainer() const
{
    return itsSecondTrainer;
}

void GameMaker::setItsSecondTrainer(Trainer *newItsSecondTrainer)
{
    itsSecondTrainer = newItsSecondTrainer;
}
