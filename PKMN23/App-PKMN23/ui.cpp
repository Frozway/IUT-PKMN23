#include "UI.h"


UI::UI()
{

}

string UI::Menu()
{
    int choice ;
    clearScreen();
    topBoard();

    cout << R"(
                                                                                      /-----------------------------\
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

    bottomBoard();
    displayInputText() ;

    while(true)
    {
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 6 )
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

    cout << YELLOW_TEXT << R"(
                                                                                                  ,'\
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
}





void UI::bottomBoard()
{
    cout << endl << R"(            \\==============================================================================================================================================================================//)" << endl;
}

void UI::clearScreen()
{
    //Récuperer les informations lié a l'OS de l'utilisateur pour que son clear fonctionne à l'appui d'une touche
    #ifdef _WIN32
    //system("pause");
    system("cls") ;

    #elif __APPLE__
    //system( "read -n 1 -s -p \"Appuyer sur une touche pour lancer le jeu\""); //Mac et Linux
    system("clear");

    #elif __linux
    //system( "read -n 1 -s -p \"Appuyer sur une touche pour lancer le jeu\""); //Mac et Linux
    system("clear");

    #endif
}

bool UI::isANewPlayer(Trainer* trainer)
{
    topBoard();

    int choice ;
    cout << CYAN_TEXT << endl;
    printCenteredText(trainer->getItsName());
    cout << endl << BLUE_TEXT ;
    printCenteredText("avez vous une sauvegarde ?");
    cout << COLOR_RESET << endl ;
    printCenteredText("[0] Non | [1] Oui") ;
    cout << endl ;
    bottomBoard();
    displayInputText() ;
    //cout << "Votre reponse : ";
    while(true)
    {
        cin >> choice;
        if(cin.fail() || (choice != 0 && choice != 1))
        {
            cout << endl << RED_TEXT ;
            printCenteredText("Votre choix n'est pas possible, veuillez recommencer :");
            cout << COLOR_RESET ;
            cin.clear(); //Réinitialiser l'entrée si une erreur à été produite pour pouvoir de nouveau entrée une valeur
            cin.ignore(10,'\n'); //Ignore un certains nombre de caractères pour ne pas prendre en compte l'entrée comme plusieurs entrée et cela à partir la fin de ligne
        }
        else
            break;
    }
    cout << endl ;

    clearScreen() ;



    if(choice == 0)
    {
        return true;
    }
    else return false;

}

void UI::displayInfoPokemon(Pokemon * pokemon)
{
    cout << pokemon->displayPokemon() ;
}

void UI::displayPokemon(Pokemon * pokemon)
{
    centerPokemon() ;

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
}

void UI::centerPokemon()
{
    cout << setfill(' ') << setw(70) << "" ;
}

void UI::displayTeamTrainer(Trainer * trainer)
{
    vector<Pokemon*> itsTrainerPokemonTeam = trainer->getItsTeam();

    cout << "X------------------------------------------------------X" << endl ;

    for (int i = 0; i < (int)itsTrainerPokemonTeam.size(); i++)
    {
        cout << "| Pokemon #" << i + 1 << ":                                          |" << endl;
        displayPokemon(itsTrainerPokemonTeam[i]);
        cout << endl ;
        if (i != 5)
        {
            cout << "x                                                      x" << endl ;
        }
    }
    cout << "X------------------------------------------------------X" << endl ;

}

string UI::setupName(Trainer * trainer)
{
    string name ;
    topBoard();
    cout << endl << BLUE_TEXT ;
    printCenteredText(trainer->getItsName() + ", quel est ton surnom");
    cout << COLOR_RESET ;
    bottomBoard();
    displayInputText();
    cin >> name ;
    cout << endl ;
    clearScreen();
    return name;
}

void UI::basicGameDialog(Trainer * firstTrainer, Trainer * secondTrainer)
{

    cout << endl << BLUE_TEXT;
    printCenteredText("Allocation des pokemon de facon aleatoire");
    cout << endl ;

    printCenteredText("Le joueur qui commencera la partie est " + firstTrainer->getItsName());

    cout << endl << endl << COLOR_RESET;

    displayInfoTrainers(firstTrainer, secondTrainer);
    bottomBoard();
}



void UI::printCenteredText(string text)
{
    int padding = 200 - text.length();
    int leftPadding = padding / 2;
    int rightPadding = padding - leftPadding;

    cout << setfill(' ') << setw(leftPadding) << "" << text << setw(rightPadding) << "" << endl;
}



void UI::displaySpace()
{
    cout << "                                   " ;

}

void UI::displayInputText()
{
    cout << endl << "                                                                                            Votre reponse : " ; //Puiss le texte qu'on veut affiché demandant une entrée utilisateur
}

void UI::displayInfoTrainer(Trainer * trainer)
{
    printCenteredText("Dresseur : " + trainer->getItsName());
    cout << endl ;
    printCenteredText("Niveau : " + to_string(trainer->getItsLevel()));
    cout << endl ;
    printCenteredText("Points : " + to_string(trainer->getItsPoints()));
    cout << endl ;
    printCenteredText("Nombre de points de vie total de l'equipe : " + to_string(trainer->getItsTotalTeamHP()) + "HP");
    cout << endl ;
    printCenteredText("Puissance de combat totale de l'equipe : " + to_string(trainer->getItsTotalCP()) + "CP");
    cout << endl ;
    printCenteredText("Vitesse moyenne de l'equipe : " + to_string(trainer->getItsAverageSpeed()) + "KM/H");
    cout << endl ;
    printCenteredText("Vitesse moyenne de l'equipe (EAU) : " + to_string(trainer->getItsAverageSpeed("WATER")) + "KM/H");
    cout << endl ;
    printCenteredText("Vitesse moyenne de l'equipe (FIRE) : " + to_string(trainer->getItsAverageSpeed("FIRE")) + "KM/H");
    cout << endl ;
    printCenteredText("Vitesse moyenne de l'equipe (GRASS) : " + to_string(trainer->getItsAverageSpeed("GRASS")) + "KM/H");
    cout << endl ;
    printCenteredText("Vitesse moyenne de l'equipe (ELECTRIK) : " + to_string(trainer->getItsAverageSpeed("ELECTRIK")) + "KM/H");
}

void UI::displayInfoTrainers(Trainer* trainer1, Trainer* trainer2)
{
    int columnWidth = 80;

    displaySpace();
    cout << setw(columnWidth) << left << "Dresseur : " + trainer1->getItsName();
    cout << setw(columnWidth) << left << "Dresseur : " + trainer2->getItsName() << endl;

    displaySpace();
    cout << setw(columnWidth) << left << "Niveau : " + to_string(trainer1->getItsLevel()) + "           Points : " + to_string(trainer1->getItsPoints());
    cout << setw(columnWidth) << left << "Niveau : " + to_string(trainer2->getItsLevel()) + "           Points : " + to_string(trainer2->getItsPoints()) << endl << endl ;

    displaySpace();
    cout << setw(columnWidth) << left << "Nombre de points de vie total de l'equipe : " + to_string(trainer1->getItsTotalTeamHP()) + " HP";
    cout << setw(columnWidth) << left << "Nombre de points de vie total de l'equipe : " + to_string(trainer2->getItsTotalTeamHP()) + " HP" << endl;

    displaySpace();
    cout << setw(columnWidth) << left << "Puissance de combat totale de l'equipe : " + to_string(trainer1->getItsTotalCP()) + " CP";
    cout << setw(columnWidth) << left << "Puissance de combat totale de l'equipe : " + to_string(trainer2->getItsTotalCP()) + " CP" << endl << endl ;

    displaySpace();
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe : " + to_string(trainer1->getItsAverageSpeed()) + " KM/H";
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe : " + to_string(trainer2->getItsAverageSpeed()) + " KM/H" << endl;

    displaySpace();
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type EAU) : " + to_string(trainer1->getItsAverageSpeed("WATER")) + " KM/H";
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type EAU) : " + to_string(trainer2->getItsAverageSpeed("WATER")) + " KM/H" << endl;

    displaySpace();
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type FIRE) : " + to_string(trainer1->getItsAverageSpeed("FIRE")) + " KM/H";
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type FIRE) : " + to_string(trainer2->getItsAverageSpeed("FIRE")) + " KM/H" << endl;

    displaySpace();
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type GRASS) : " + to_string(trainer1->getItsAverageSpeed("GRASS")) + " KM/H";
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type GRASS) : " + to_string(trainer2->getItsAverageSpeed("GRASS")) + " KM/H" << endl;

    displaySpace();
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type ELECTRIK) : " + to_string(trainer1->getItsAverageSpeed("ELECTRIK")) + " KM/H";
    cout << setw(columnWidth) << left << "Vitesse moyenne de l'equipe (Type ELECTRIK) : " + to_string(trainer2->getItsAverageSpeed("ELECTRIK")) + " KM/H" << endl;
}

void UI::displayFight(Pokemon* pokemon1, Pokemon* pokemon2)
{
    cout << endl ;
    centerPokemon();
    cout << "x------------------------------------------------------x" << endl ;

    centerPokemon();
    cout << "|                                                      |" << endl ;

    displayPokemon(pokemon1);

    cout << endl ;
    centerPokemon();
    cout << "|                                                      |" << endl ;

    centerPokemon();
    cout << "|-----------------------VERSUS-------------------------|" ;

    cout << endl ;
    centerPokemon();
    cout << "|                                                      |" << endl ;

    displayPokemon(pokemon2);

    cout << endl ;

    centerPokemon();
    cout << "|                                                      |" << endl ;

    centerPokemon();
    cout << "x------------------------------------------------------x" << endl;
}

