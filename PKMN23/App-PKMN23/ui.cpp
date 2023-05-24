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
                                                                                      | [3] : Demo (IA VS IA)       |
                                                                                      |                             |
                                                                                      | [4] : Regles du jeu         |
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

        case 4 : return "REGLES";

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
                                                                                                `'                            '-._|

)"
        << COLOR_RESET <<R"(            //==============================================================================================================================================================================\\)" << endl;
    cout << endl ;
}

void UI::bottomBoard()
{
    cout << endl << R"(            \\==============================================================================================================================================================================//)" << endl;
    cout << endl ;
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
    // Pause pendant le nombre de secondes spécifié
    #ifdef _WIN32
        // Windows
        sleep(time);
    #else
        // UNIX
        sleep(time);
    #endif
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
    else if(pokemon->getItsType() == "ELECTRIK")
    {
        printf("| %-13s (ELECTRIK) : %-3i PV | %-3i CP | %-5.2f KM/H |",
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
    //printCenteredText("Dresseur : " + trainer->getItsName());
    printCenteredText("Niveau : " + to_string(trainer->getItsLevel()));
    printCenteredText("Points : " + to_string(trainer->getItsPoints()));
    printCenteredText("Nombre de points de vie total de l'equipe : " + to_string(trainer->getItsTotalTeamHP()) + "HP");
    printCenteredText("Puissance de combat totale de l'equipe : " + to_string(trainer->getItsTotalCP()) + "CP");
    printCenteredText("Vitesse moyenne de l'equipe : " + to_string(trainer->getItsAverageSpeed()) + "KM/H");
    printCenteredText("Vitesse moyenne de l'equipe (EAU) : " + to_string(trainer->getItsAverageSpeed("WATER")) + "KM/H");
    printCenteredText("Vitesse moyenne de l'equipe (FIRE) : " + to_string(trainer->getItsAverageSpeed("FIRE")) + "KM/H");
    printCenteredText("Vitesse moyenne de l'equipe (GRASS) : " + to_string(trainer->getItsAverageSpeed("GRASS")) + "KM/H");
    printCenteredText("Vitesse moyenne de l'equipe (ELECTRIK) : " + to_string(trainer->getItsAverageSpeed("ELECTRIK")) + "KM/H");
}

void UI::displayInfoTrainers(Trainer* trainer1, Trainer* trainer2)
{
    int columnWidth = 80;

    setCenteredTextForTeamsColumns();
    cout << CYAN_TEXT << setw(columnWidth) << left << "Attaquant : " + trainer1->getItsName();
    cout << BLUE_TEXT << setw(columnWidth) << left << "Defenseur : " + trainer2->getItsName() << endl;

    cout << COLOR_RESET ;

    setCenteredTextForTeamsColumns();
    cout << setw(columnWidth) << left << "Niveau : " + to_string(trainer1->getItsLevel()) + "           Points : " + to_string(trainer1->getItsPoints());
    cout << setw(columnWidth) << left << "Niveau : " + to_string(trainer2->getItsLevel()) + "           Points : " + to_string(trainer2->getItsPoints()) << endl << endl ;

    setCenteredTextForTeamsColumns();
    //cout << setw(columnWidth) << left << "Nombre de points de vie total de l'equipe : " + to_string(trainer1->getItsTotalTeamHP()) + " HP";
    //cout << setw(columnWidth) << left << "Nombre de points de vie total de l'equipe : " + to_string(trainer2->getItsTotalTeamHP()) + " HP" << endl;

//    setCenteredTextForTeamsColumns();
//    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe : " + to_string(trainer1->getItsAverageSpeed()) + " KM/H";
//    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe : " + to_string(trainer2->getItsAverageSpeed()) + " KM/H" << endl;

//    setCenteredTextForTeamsColumns();
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type EAU) : " + to_string(trainer1->getItsAverageSpeed("WATER")) + " KM/H";
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type EAU) : " + to_string(trainer2->getItsAverageSpeed("WATER")) + " KM/H" << endl;

//    setCenteredTextForTeamsColumns();
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type FIRE) : " + to_string(trainer1->getItsAverageSpeed("FIRE")) + " KM/H";
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type FIRE) : " + to_string(trainer2->getItsAverageSpeed("FIRE")) + " KM/H" << endl;

//    setCenteredTextForTeamsColumns();
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type GRASS) : " + to_string(trainer1->getItsAverageSpeed("GRASS")) + " KM/H";
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type GRASS) : " + to_string(trainer2->getItsAverageSpeed("GRASS")) + " KM/H" << endl;

//    setCenteredTextForTeamsColumns();
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type ELECTRIK) : " + to_string(trainer1->getItsAverageSpeed("ELECTRIK")) + " KM/H";
//    cout << setw(columnWidth) << left << "Vitesse moyenne (Type ELECTRIK) : " + to_string(trainer2->getItsAverageSpeed("ELECTRIK")) + " KM/H" << endl;
}

void UI::displayTeamTrainer(Trainer * trainer)
{
    setCenteredTextForAPokemon();
    cout << "X------------------------------------------------------X" << endl ;

    for (int i = 0; i < 6; i++)
    {
        setCenteredTextForAPokemon() ;
        displayPokemon(trainer->getItsTeam()[i]);
        setCenteredTextForAPokemon();
        cout << endl ;
        if (i != 5)
        {
            setCenteredTextForAPokemon();
            cout << "x                                                      x" << endl ;
        }
    }
    setCenteredTextForAPokemon();
    cout << "X------------------------------------------------------X" << endl ;

}

void UI::displayTeamsTrainers(Trainer* trainer1, Trainer* trainer2)
{
    cout << endl ;
    setCenteredTextForTeamsColumns();
    cout << "X------------------------------------------------------X" ;
    cout << setfill(' ') << setw(24) << "" ;
    cout << "X------------------------------------------------------X" << endl ;

    for (int i = 0; i < 6; i++)
    {
        setCenteredTextForTeamsColumns();
        displayPokemon(trainer1->getItsTeam()[i]);
        cout << setfill(' ') << setw(24) << "" ;
        displayPokemon(trainer2->getItsTeam()[i]);
        cout << endl ;
        if (i != 5)
        {
            setCenteredTextForTeamsColumns();;
            cout << "x                                                      x" ;
            cout << setfill(' ') << setw(24) << "" ;
            cout << "x                                                      x" << endl ;
        }
    }
    setCenteredTextForTeamsColumns();;
    cout << "X------------------------------------------------------X" ;
    cout << setfill(' ') << setw(24) << "" ;
    cout << "X------------------------------------------------------X" << endl ;
}

//*************************************************************** DIALOGUE DE MISE EN PLACE *********************************************************************************//

bool UI::isANewPlayer(Trainer* trainer)
{
    topBoard();

    int choice ;
    cout << CYAN_TEXT ;
    printCenteredText(trainer->getItsName());
    cout << BLUE_TEXT ;
    printCenteredText("avez vous une sauvegarde ?");
    cout << COLOR_RESET ;
    printCenteredText("[0] Non | [1] Oui") ;
    bottomBoard();
    setCenteredTextForInput() ;
    //cout << "Votre reponse : ";
    while(true)
    {
        cin >> choice;
        if(cin.fail() || (choice != 0 && choice != 1))
        {
            cout << RED_TEXT ;
            printCenteredText("Votre choix n'est pas possible, veuillez recommencer :");
            cout << COLOR_RESET ;
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
            break;
    }
    cout << endl ;

    fastClearScreen() ;



    if(choice == 0)
    {
        return true;
    }
    else return false;

}

string UI::setupName(Trainer * trainer)
{
    string name ;
    topBoard();
    cout << BLUE_TEXT ;
    printCenteredText(trainer->getItsName() + ", quel est ton surnom");
    cout << COLOR_RESET ;
    bottomBoard();
    setCenteredTextForInput();
    cin >> name ;
    cout << endl ;
    fastClearScreen();
    return name;
}

//*************************************************************** AFFICHAGE EN JEU *********************************************************************************//

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

    string attack1 = "Le pokemon " + trainer1->getFighterPokemon()->getItsName() + " inflige " + to_string(trainer1->getFighterPokemon()->nbDamage(trainer2->getFighterPokemon())) + " degats a " + trainer2->getFighterPokemon()->getItsName() ;

    pauseText(2);

    printCenteredText(attack1);

    pauseText(2);

}

void UI::displayFightWinner(Trainer * trainer1, Trainer * trainer2)
{
    Trainer * winner = nullptr;
    cout << RED_TEXT ;
    if(trainer1->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        winner = trainer2 ;
        printCenteredText("Le pokemon " + trainer1->getFighterPokemon()->getItsName() + " de " + trainer1->getItsName() + " est KO !");
    }
    if(trainer2->getFighterPokemon()->getItsCurrentHP() == 0)
    {
        winner = trainer1 ;
        printCenteredText("Le pokemon " + trainer2->getFighterPokemon()->getItsName() + " de " + trainer2->getItsName() + " est KO !");
    }
    cout << COLOR_RESET ;

    clearScreen();
    topBoard();
    displayInfoTrainers(trainer1, trainer2);
    displayTeamsTrainers(trainer1, trainer2);

    cout << GREEN_TEXT << endl ;
    printCenteredText("Le gagnant de ce combat est " + winner->getItsName() + " avec son pokemon " + winner->getFighterPokemon()->getItsName());
    cout << COLOR_RESET ;
    bottomBoard();
}

void UI::displayGameWinner(Trainer * winner)
{
    clearScreen();
    topBoard();
    cout << GREEN_TEXT << endl ;
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
    cout<< "Votre reponse : " ;
}




