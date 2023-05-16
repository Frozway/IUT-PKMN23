#include <iostream>
//#include "electrikpokemon.h"
//#include "grasspokemon.h"
//#include "pokemon.h"
//#include "trainer.h"
//#include "waterpokemon.h"
//#include "firepokemon.h"
//#include "ui.h"

#include "gamemaker.h"

using namespace std;

int main()
{


    //UI UserInterface;


    DataBase * Database = new DataBase();
    QSqlDatabase db = Database->initDataBase() ;

    Trainer* trainer1 = new Trainer("Sacha");

    Database->fillARandomTeam(trainer1, db);



    trainer1->displayTeam();




    //UserInterface.displayMenu();
//    // Création des 12 Pokémon
//    Pokemon* carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 70, 30, 4);
//    Pokemon* bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 70, 30);
//    Pokemon* salameche = new FirePokemon("Salameche", 0.65, 12, 70, 70, 30, 2);
//    Pokemon* pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 70, 30, 2, 0, 50);
//    Pokemon* dracaufeu = new FirePokemon("Dracaufeu", 1.7, 90, 150, 150, 60, 4);
//    Pokemon* florizarre = new GrassPokemon("Florizarre", 2.0, 100, 160, 160, 60);
//    Pokemon* tortank = new WaterPokemon("Tortank", 1.6, 85, 140, 140, 50, 5);
//    Pokemon* raichu = new ElectrikPokemon("Raichu", 0.8, 30, 80, 80, 40, 3, 0, 60);
//    Pokemon* lapras = new WaterPokemon("Lapras", 2.5, 220, 180, 180, 60, 5);
//    Pokemon* jolteon = new ElectrikPokemon("Jolteon", 0.8, 24, 75, 75, 35, 3, 0, 65);
//    Pokemon* charizard = new FirePokemon("Charizard", 1.7, 90, 150, 150, 60, 4);
//    Pokemon* vaporeon = new WaterPokemon("Vaporeon", 1.0, 29, 110, 110, 45, 4);


//    // Création d'un dresseur
//    Trainer* trainer1 = new Trainer("Sacha");
//    Trainer* trainer2 = new Trainer("Thibaut");

//    trainer1->catchPokemon(carapuce);
//    trainer1->catchPokemon(bulbizarre);
//    trainer1->catchPokemon(salameche);
//    trainer1->catchPokemon(pikachu);
//    trainer1->catchPokemon(dracaufeu);
//    trainer1->catchPokemon(florizarre);

//    trainer2->catchPokemon(tortank);
//    trainer2->catchPokemon(raichu);
//    trainer2->catchPokemon(lapras);
//    trainer2->catchPokemon(jolteon);
//    trainer2->catchPokemon(charizard);
//    trainer2->catchPokemon(vaporeon);

//    trainer1->displayTeam();
//    trainer1->displayTrainer();

//    cout << endl << endl << endl << "=================================================================" << endl << endl << endl ;


//    trainer2->displayTeam();
//    trainer2->displayTrainer();

//    cout << endl << endl << endl << "=================================================================" << endl << endl << endl ;

//    //trainer1->attack(tortank, charizard);
//    //trainer1->attack(tortank, charizard);
//    trainer2->displayTeam();


    return 0;
}
