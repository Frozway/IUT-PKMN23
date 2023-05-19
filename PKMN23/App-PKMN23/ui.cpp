#include "ui.h"

UI::UI()
{

}

void UI::displayMenu()
{
    int choice ;

    clearScreen();

    cout << R"(
            //==========================================================\\

                          /-----------------------------\
                          |     PokemonCard - Menu      |
                          |-----------------------------|
                          |                             |
                          | [1] : Solo VS IA            |
                          |                             |
                          | [2] : Multijoueur           |
                          |                             |
                          | [4] : Regles du jeu         |
                          |                             |
                          | [5] : Quitter le jeu        |
                          |                             |
                          \-----------------------------/

            \\==========================================================//

                            Quel est votre choix : )";
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
        case 1 : //soloMode();
        break;

        case 2 : //multiMode();
        break;

        case 3 : //launchTest();
        break;

        case 4 : //launchRules();

        case 5 : break ;

        break;
    }
}

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

void UI::displayInfoTrainer(Trainer * trainer)
{
    cout << "Dresseur : " << trainer->getItsName() << endl ;
    cout << "Niveau : " << trainer->getItsLevel() << endl ;
    cout << "Points : " << trainer->getItsPoints() << endl ;
    cout << "Nombre de points de vie total de l'equipe : " << trainer->getItsTotalTeamHP() << " HP" << endl ;
    cout << "Puissance de combat totale de l'equipe : " << trainer->getItsTotalCP() << " CP" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe : " << trainer->getItsAverageSpeed() << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type EAU) : " << trainer->getItsAverageSpeed("WATER") << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type FIRE): " << trainer->getItsAverageSpeed("FIRE") << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type GRASS): " << trainer->getItsAverageSpeed("GRASS") << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type ELECTRIK): " << trainer->getItsAverageSpeed("ELECTRIK") << " KM/H" << endl ;
}

void UI::displayInfoPokemon(Pokemon * pokemon)
{
    cout << pokemon->getItsName() << " (" << pokemon->getItsType() <<") | "
         << pokemon->getItsMaxHP() << " HP | " << pokemon->getItsCP()
         << " PC | " << pokemon->getItsSpeed() << " KM/H | "
         << pokemon->getItsHeight() << " M | " << pokemon->getItsWeight() << " KG | " ;
}

void UI::displayTeamTrainer(Trainer * trainer)
{
    vector<Pokemon*> itsTrainerPokemonTeam = trainer->getItsTeam();

    for (int i = 0; i < (int)itsTrainerPokemonTeam.size(); i++)
    {
        cout << "Pokemon #" << i + 1 << ":" << endl;
        (itsTrainerPokemonTeam)[i]->displayPokemon();
        cout << endl;
    }

}
