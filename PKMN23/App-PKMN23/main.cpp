#include <iostream>

#if defined _WIN32
    #include <Windows.h>
#endif

#include "gamemaker.h"
#include "QAnyStringView"




using namespace std;

int main()
{
    // Active l'encodage utf-8 dans le terminal pour windows
    #if defined _WIN32
        // Set console code page to UTF-8 so console known how to interpret string data
        SetConsoleOutputCP(CP_UTF8);

        // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
        setvbuf(stdout, nullptr, _IOFBF, 1000);
    #endif

    //Création de l'application
    GameMaker * Game = new GameMaker();

    //Lancement du jeu
    Game->Play();

    //Suppression du jeu
    delete Game ;

    return 0;
}
