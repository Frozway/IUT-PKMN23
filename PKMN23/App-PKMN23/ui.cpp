#include "UI.h"


UI::UI()
{

}

//*********************************************************** MENU & PLATEAU TEMPLATE *************************************************************************************//

string UI::Menu()
{
    //Nettoyer l'écran pour éviter les bugs
    fastClearScreen();

    //Afficher le haut du plateau
    topBoard();

    cout << R"(                                                                                      /-----------------------------\
                                                                                      |     PokemonCard - Menu      |
                                                                                      |-----------------------------|
                                                                                      |                             |
                                                                                      | [1] : Solo VS IA            |
                                                                                      |                             |
                                                                                      | [2] : Multijoueur           |
                                                                                      |                             |
                                                                                      | [3] : Démo (IA VS IA)       |
                                                                                      |                             |
                                                                                      | [4] : Règles du jeu         |
                                                                                      |                             |
                                                                                      | [5] : Quitter le jeu        |
                                                                                      |                             |
                                                                                      \-----------------------------/
)";

    //Afficher le bas du plateau
    bottomBoard();

    setCenteredTextForInput() ;

    int choice ;
    while(true)
    {
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 5 )
        {
            cout << endl << RED_TEXT << "               " << "Votre choix n'est pas possible, veuillez recommencer : " << COLOR_RESET;
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
            break;
    }
    cout << endl ;

    switch(choice)
    {
        case 1 : return "SOLO VS IA";
        break;

        case 2 : return "MULTIJOUEUR";
        break;

        case 3 : return "DEMO";
        break;

        case 4 : displayRules();

        case 5 : break ;

        break;
    }

    return "BREAK" ;
}

void UI::topBoard()
{

    cout << YELLOW_TEXT << R"(                                                                                                  ,'\
                                                                    _.----.        ____         ,'  _\   ___    ___     ____
                                                                _,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
                                                                \      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
                                                                 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
                                                                   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
                                                                    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
                                                                     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
                                                                      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
                                                                       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
                                                                        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                                                                                `'                            '-._| by Thibaut LEFRANCOIS D2

)"
        << COLOR_RESET <<R"(            //==============================================================================================================================================================================\\)" << endl;
    cout << endl ;
}

void UI::bottomBoard()
{
    cout << endl << R"(            \\==============================================================================================================================================================================//)" << endl;
    cout << endl ;
}

void UI::displayRules()
{
    clearScreen();
    topBoard();

    cout << CYAN_TEXT;
    printCenteredText("Règles du Jeu");
    cout << COLOR_RESET;

    // Affichage des règles du jeu, centrées
    cout << "\n";
    printCenteredText("1. Chaque joueur sélectionne un mode de jeu et se créé leur propre Trainer pour jouer.");
    printCenteredText("2. Les dresseurs s'affrontent en utilisant leurs Pokémon pour se battre.");
    printCenteredText("3. Chaque Pokémon possède des points de vie (PV), des points de combat (CP), une vitesse et plus encore.");
    printCenteredText("4. Le joueur dont tous les Pokémon sont KO perd la partie.");
    printCenteredText("5. Le joueur qui à un Pokémon KO lors d'un combat se voit perdre celui-ci.");
    printCenteredText("6. Les équipes sont définis aléatoirement, mais il est possible de transférer un Pokémon pour en changer un (en début de partie).");
    printCenteredText("7. Les joueurs peuvent choisir leur Pokémon pour attaquer, ainsi qu'ils décident de changer ou non après un combat gagné.");

    bottomBoard();

    clearScreen();

    Menu();
}

//************************************************************** NETTOYAGE & FLUIDITE **********************************************************************************//

void UI::clearScreen()
{
    //Récuperer les informations lié a l'OS de l'utilisateur pour que son clear fonctionne à l'appui d'une touche
    #ifdef _WIN32
    system("pause");
    system("cls") ;

    #elif __APPLE__
    system( "read -n 1 -s -p \"Appuyer sur une touche pour lancer le jeu\""); //Mac et Linux
    system("clear");

    #elif __linux
    system( "read -n 1 -s -p \"Appuyer sur une touche pour lancer le jeu\""); //Mac et Linux
    system("clear");

    #endif
}

void UI::fastClearScreen()
{
    //Récuperer les informations lié a l'OS de l'utilisateur pour que son clear fonctionne à l'appui d'une touche
    #ifdef _WIN32
    system("cls") ;

    #elif __APPLE__
    system("clear");

    #elif __linux
    system("clear");

    #endif
}

void UI::pauseText(int time)
{
    sleep(time);
}

//**************************************************************** POKEMON ********************************************************************************//

void UI::displayPokemon(Pokemon * pokemon)
{
    if(pokemon->getItsCurrentHP() == 0)
    {
        cout << RED_TEXT ;
    }
    //Formatage de l'affichage d'un pokémon avec printf pour garder le même format à l'affichage de chaque pokémon
    // % : variable | <nombre> : longeur maximum autorisé pour la variable | <s/i/f> : type de la variable (string/int/float)
    if(pokemon->getItsType() == "FIRE")
    {
        printf("| %-13s (FIRE)  : %-3i PV | %-3i CP | %-5.2f KM/H |",
                       pokemon->getItsName().c_str(),
                       pokemon->getItsCurrentHP(),
                       pokemon->getItsCP(),
                       pokemon->getItsSpeed());
    }
    else if(pokemon->getItsType() == "GRASS")
    {
        printf("| %-13s (GRASS) : %-3i PV | %-3i CP | %-5.2f KM/H |",
                       pokemon->getItsName().c_str(),
                       pokemon->getItsCurrentHP(),
                       pokemon->getItsCP(),
                       pokemon->getItsSpeed());
    }
    else if(pokemon->getItsType() == "WATER")
    {
        printf("| %-13s (WATER) : %-3i PV | %-3i CP | %-5.2f KM/H |",
                       pokemon->getItsName().c_str(),
                       pokemon->getItsCurrentHP(),
                       pokemon->getItsCP(),
                       pokemon->getItsSpeed());
    }
    else{
        printf("| %-10s (ELECTRIK) : %-3i PV | %-3i CP | %-5.2f KM/H |",
                       pokemon->getItsName().c_str(),
                       pokemon->getItsCurrentHP(),
                       pokemon->getItsCP(),
                       pokemon->getItsSpeed());
    }
    cout << COLOR_RESET;
}

void UI::displayInfoPokemon(Pokemon * pokemon)
{
    //Récupéré les informations détaillés du pokémon
    //Info spécifique à son type avec une phrase de présentation (cahier des charges)
    cout << pokemon->displayPokemon() ;
}

//************************************************************* TRAINER ***********************************************************************************//

void UI::displayInfoTrainer(Trainer * trainer)
{
    cout << BLUE_TEXT ;
    printCenteredText("Voici les informations du joueur " +trainer->getItsName());
    cout << COLOR_RESET;
    printCenteredText("Niveau : " + to_string(trainer->getItsLevel()));
    printCenteredText("Points : " + to_string(trainer->getItsPoints()));
    printCenteredText("Nombre de points de vie total de l'equipe : " + to_string(trainer->getItsTotalTeamHP()) + "HP");
    printCenteredText("Puissance de combat totale de l'equipe : " + to_string(trainer->getItsTotalCP()) + "CP");
    printCenteredText("Vitesse moyenne de l'équipe : " + to_string(trainer->getItsAverageSpeed()) + "KM/H");
    printCenteredText("Vitesse moyenne de l'équipe (EAU) : " + to_string(trainer->getItsAverageSpeed("WATER")) + "KM/H");
    printCenteredText("Vitesse moyenne de l'équipe (FIRE) : " + to_string(trainer->getItsAverageSpeed("FIRE")) + "KM/H");
    printCenteredText("Vitesse moyenne de l'équipe (GRASS) : " + to_string(trainer->getItsAverageSpeed("GRASS")) + "KM/H");
    printCenteredText("Vitesse moyenne de l'équipe (ELECTRIK) : " + to_string(trainer->getItsAverageSpeed("ELECTRIK")) + "KM/H");
}

void UI::displayInfoTrainers(Trainer* trainer1, Trainer* trainer2)
{
    int columnWidth = 80;

    setCenteredTextForTeamsColumns();

    // Affichage des noms des dresseurs attaquant et défenseur
    cout << CYAN_TEXT << setw(columnWidth) << left << "Attaquant : " + trainer1->getItsName();
    cout << BLUE_TEXT << setw(columnWidth) << left << "Defenseur : " + trainer2->getItsName() << endl;

    cout << COLOR_RESET;

    setCenteredTextForTeamsColumns();

    // Affichage des niveaux et points des dresseurs attaquant et défenseur
    cout << setw(columnWidth) << left << "Niveau : " + to_string(trainer1->getItsLevel()) + "           Points : " + to_string(trainer1->getItsPoints());
    cout << setw(columnWidth) << left << "Niveau : " + to_string(trainer2->getItsLevel()) + "           Points : " + to_string(trainer2->getItsPoints()) << endl << endl;

    setCenteredTextForTeamsColumns();
}

void UI::displayTeamTrainer(Trainer* trainer)
{
    setCenteredTextForAPokemon();

    // Affichage de la bordure supérieure
    cout << "X------------------------------------------------------X" << endl;

    for (int i = 0; i < 6; i++)
    {
        setCenteredTextForAPokemon();

        // Affichage du Pokémon du dresseur
        displayPokemon(trainer->getItsTeam()[i]);

        setCenteredTextForAPokemon();
        cout << endl;

        if (i != 5)
        {
            setCenteredTextForAPokemon();

            // Affichage de la séparation entre les Pokémon
            cout << "x                                                      x" << endl;
        }
    }

    setCenteredTextForAPokemon();

    // Affichage de la bordure inférieure
    cout << "X------------------------------------------------------X" << endl;
}

void UI::displayTeamsTrainers(Trainer* trainer1, Trainer* trainer2)
{
    cout << endl;

    setCenteredTextForTeamsColumns();

    // Affichage de la bordure supérieure
    cout << "X------------------------------------------------------X";
    cout << setfill(' ') << setw(24) << "";
    cout << "X------------------------------------------------------X" << endl;

    for (int i = 0; i < 6; i++)
    {
        setCenteredTextForTeamsColumns();

        // Affichage des Pokémon des deux dresseurs côte à côte
        displayPokemon(trainer1->getItsTeam()[i]);
        cout << setfill(' ') << setw(24) << "";
        displayPokemon(trainer2->getItsTeam()[i]);
        cout << endl;

        if (i != 5)
        {
            setCenteredTextForTeamsColumns();

            // Affichage de la séparation entre les équipes de Pokémon
            cout << "x                                                      x";
            cout << setfill(' ') << setw(24) << "";
            cout << "x                                                      x" << endl;
        }
    }

    setCenteredTextForTeamsColumns();

    // Affichage de la bordure inférieure
    cout << "X------------------------------------------------------X";
    cout << setfill(' ') << setw(24) << "";
    cout << "X------------------------------------------------------X" << endl;
}


//*************************************************************** DIALOGUE DE MISE EN PLACE *********************************************************************************//

bool UI::isNewSetFighter(Trainer* trainer)
{
    clearScreen();
    topBoard();

    // Affichage du nom du dresseur
    cout << CYAN_TEXT;
    printCenteredText(trainer->getItsName());

    cout << BLUE_TEXT;
    printCenteredText("Voulez-vous changer de Pokémon pour le prochain combat ?");
    cout << COLOR_RESET;
    printCenteredText("[0] Non | [1] Oui");

    bottomBoard();

    setCenteredTextForInput();

    int choice;

    while(true)
    {
        cin >> choice;

        if(cin.fail() || (choice != 0 && choice != 1))
        {
            cout << RED_TEXT;
            printCenteredText("Votre choix n'est pas possible, veuillez recommencer :");
            cout << COLOR_RESET;

            cin.clear(); // Réinitialiser l'entrée si une erreur a été produite pour pouvoir de nouveau entrer une valeur
            cin.ignore(10,'\n'); // Ignorer un certain nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrées, à partir de la fin de ligne
        }
        else
        {
            break;
        }
    }

    cout << endl;

    if(choice == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool UI::isANewPlayer(Trainer* trainer)
{
    topBoard();

    int choice;
    cout << CYAN_TEXT << endl;
    printCenteredText(trainer->getItsName());
    cout << BLUE_TEXT;
    printCenteredText("Avez-vous un compte ?");
    cout << COLOR_RESET;
    printCenteredText("[0] Non | [1] Oui");
    bottomBoard();
    setCenteredTextForInput();

    while(true)
    {
        cin >> choice;

        if(cin.fail() || (choice != 0 && choice != 1))
        {
            cout << RED_TEXT;
            printCenteredText("Votre choix n'est pas possible, veuillez recommencer :");
            cout << COLOR_RESET;

            cin.clear(); // Réinitialiser l'entrée si une erreur a été produite pour pouvoir de nouveau entrer une valeur
            cin.ignore(10,'\n'); // Ignorer un certain nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrées, à partir de la fin de ligne
        }
        else
        {
            break;
        }
    }

    cout << endl;

    fastClearScreen();

    if(choice == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string UI::setupName(Trainer * trainer)
{
    string name ;
    topBoard();
    cout << BLUE_TEXT << endl ;
    printCenteredText(trainer->getItsName() + ", quel est ton surnom ?");
    cout << COLOR_RESET ;
    bottomBoard();
    setCenteredTextForInput();
    cin >> name ;
    cout << endl ;
    fastClearScreen();
    return name;
}

//*************************************************************** AFFICHAGE EN JEU *********************************************************************************//

void UI::displaySetFighter(Trainer * trainer)
{
    clearScreen();
    topBoard();

    int choice = 0;

    cout << CYAN_TEXT ;
    printCenteredText(trainer->getItsName());
    cout << BLUE_TEXT;
    printCenteredText("Parmis les Pokémon ci-dessous, lequel veux tu choisir pour le combat ? (Entrez le numéro)");
    cout << COLOR_RESET;

    displayTeamTrainer(trainer);

    bottomBoard();

    setCenteredTextForInput();

    do
    {

        cin >> choice ;

        if(choice < 1 || choice >= 7 )
        {
            cout << RED_TEXT ;
            printCenteredText("Indice invalide ! Choissisez un Pokémon entre 1 et 6, recommencez :");
            cout << COLOR_RESET ;
        }
        else if(trainer->getItsTeam()[choice-1]->getItsCurrentHP() == 0)
                {
                    cout << RED_TEXT ;
                    printCenteredText("Impossible de choisir ce Pokémon, il est mort ! Recommencez :");
                    cout << COLOR_RESET ;
                }
    }
    while(trainer->getItsTeam()[choice-1]->getItsCurrentHP() == 0 || choice >= 7);

    trainer->setFighterPokemon(trainer->getItsTeam()[choice-1]);

    cout << GREEN_TEXT << endl ;

    printCenteredText("Le Pokémon qui combattra à tes côtés est : " + trainer->getFighterPokemon()->getItsName());

    cout << COLOR_RESET ;


}

int UI::displayTransferPokemon(Trainer * trainer)
{
    cout << BLUE_TEXT << endl;
    printCenteredText("Souhaites tu transférer un Pokémon parmis ton équipe ?");
    cout << COLOR_RESET;
    printCenteredText("[0] Non | [1] Oui") ;

    bottomBoard();

    int choice = 0 ;

    setCenteredTextForInput();

    cin >> choice ;

    if(choice == 1)
    {
        clearScreen();
        topBoard();

        int indexPokemonToTransfer = 0;

        cout << BLUE_TEXT;
        printCenteredText("Parmis les Pokémon ci-dessous, lequel veux tu transférer ? (Entrez le numéro)");
        cout << COLOR_RESET;

        displayTeamTrainer(trainer);

        bottomBoard() ;

        setCenteredTextForInput();

        do
        {
            cin >> indexPokemonToTransfer;

            if (indexPokemonToTransfer < 1 || indexPokemonToTransfer > 6)
            {
                cout << RED_TEXT;
                printCenteredText("Indice invalide ! Choisissez un Pokémon entre 1 et 6, recommencez :");
                cout << COLOR_RESET;
            }
        }
        while (indexPokemonToTransfer < 1 || indexPokemonToTransfer > 6);

        // Vérifier si l'indice est valide avant d'accéder au vecteur itsTeam
            if (indexPokemonToTransfer <= (int)trainer->getItsTeam().size())
            {
                // Utiliser l'indice corrigé pour accéder au Pokémon dans le vecteur
                Pokemon *pokemonToTransfer = trainer->getItsTeam()[indexPokemonToTransfer - 1];

                cout << GREEN_TEXT << endl;
                printCenteredText("Le Pokémon qui a été transféré est : " + pokemonToTransfer->getItsName());
                cout << COLOR_RESET;

                clearScreen();

                topBoard();
                cout << CYAN_TEXT ;
                printCenteredText(trainer->getItsName());
                cout << BLUE_TEXT;

                printCenteredText("Voici ta nouvelle équipe :");
                cout << COLOR_RESET;

                return indexPokemonToTransfer;
            }

    }
    return 0 ;

}

void UI::displayFight(Trainer * trainer1, Trainer * trainer2)
{

    clearScreen();
    topBoard();

    displayInfoTrainers(trainer1, trainer2);
    displayTeamsTrainers(trainer1, trainer2);

    cout << endl ;
    setCenteredTextForAPokemon();

    cout << "x------------------------------------------------------x" << endl ;

    setCenteredTextForAPokemon();
    cout << "|                                                      |" << endl ;

    setCenteredTextForAPokemon() ;
    cout << CYAN_TEXT;
    displayPokemon(trainer1->getFighterPokemon());
    cout << COLOR_RESET;

    cout << endl ;
    setCenteredTextForAPokemon();
    cout << "|                                                      |" << endl ;

    setCenteredTextForAPokemon();
    cout << "|-----------------------VERSUS-------------------------|" ;

    cout << endl ;
    setCenteredTextForAPokemon();
    cout << "|                                                      |" << endl ;

    setCenteredTextForAPokemon() ;
    cout << BLUE_TEXT ;
    displayPokemon(trainer2->getFighterPokemon());
    cout << COLOR_RESET ;

    cout << endl ;

    setCenteredTextForAPokemon();
    cout << "|                                                      |" << endl ;

    setCenteredTextForAPokemon();
    cout << "x------------------------------------------------------x" << endl;

    bottomBoard() ;

    string attackText = "Le Pokémon " + trainer1->getFighterPokemon()->getItsName() + " inflige " + to_string(trainer1->getFighterPokemon()->nbDamage(trainer2->getFighterPokemon())) + " dégâts à " + trainer2->getFighterPokemon()->getItsName() ;

    if(trainer1->getFighterPokemon()->nbDamage(trainer2->getFighterPokemon()) == 2* trainer1->getFighterPokemon()->getItsCP())
    {
        attackText += " (SUPER EFFICACE)" ;
    }
    else if(trainer1->getFighterPokemon()->nbDamage(trainer2->getFighterPokemon()) == 0.5 * trainer1->getFighterPokemon()->getItsCP())
    {
        attackText += " (PEU EFFICACE)";
    }

    pauseText(2);

    printCenteredText(attackText);

    pauseText(2);

}

void UI::displayFightWinner(Trainer * trainer1, Trainer * trainer2)
{
    Trainer * winner = nullptr;
    cout << RED_TEXT ;
    if(trainer1->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        winner = trainer2 ;
        printCenteredText("Le Pokémon " + trainer1->getFighterPokemon()->getItsName() + " de " + trainer1->getItsName() + " est KO !");
    }
    if(trainer2->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        winner = trainer1 ;
        printCenteredText("Le Pokémon " + trainer2->getFighterPokemon()->getItsName() + " de " + trainer2->getItsName() + " est KO !");
    }
    cout << COLOR_RESET ;

    clearScreen();
    topBoard();
    displayInfoTrainers(trainer1, trainer2);
    displayTeamsTrainers(trainer1, trainer2);

    cout << GREEN_TEXT << endl ;
    printCenteredText("Le gagnant de ce combat est " + winner->getItsName() + " avec son Pokémon " + winner->getFighterPokemon()->getItsName());
    cout << COLOR_RESET ;
    bottomBoard();
}

void UI::displayGameWinner(Trainer * winner)
{
    clearScreen();
    topBoard();
    cout << GREEN_TEXT ;
    printCenteredText("Le gagnant de cette partie est " + winner->getItsName());

    displayInfoTrainer(winner);
    displayTeamTrainer(winner);

    bottomBoard();
}

//*************************************************************** FONCTION DE CENTRAGE *********************************************************************************//

void UI::printCenteredText(string text)
{
    int padding = 200 - text.length();
    int leftPadding = padding / 2;
    int rightPadding = padding - leftPadding;

    cout << setfill(' ') << setw(leftPadding) << "" << text << setw(rightPadding) << "" << endl ;
    cout << endl ;
}

void UI::setCenteredTextForAPokemon()
{
    cout << setfill(' ') << setw(70) << "" ;
}

void UI::setCenteredTextForTeamsColumns()
{
    cout << setfill(' ') << setw(35) << "" ;
}

void UI::setCenteredTextForInput()
{
    cout << setfill(' ') << setw(92) << "" ;
    cout<< "Votre réponse : " ;
}


