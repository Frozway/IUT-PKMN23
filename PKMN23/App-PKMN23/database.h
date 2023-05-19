#ifndef POKEMONDATABASE_H
#define POKEMONDATABASE_H

#include<iostream>
#include<QString>

#include <QSqlDatabase>
#include <QSqlQuery>
#include "trainer.h"
#include "pokemon.h"
#include "firepokemon.h"
#include "electrikpokemon.h"
#include "grasspokemon.h"
#include "waterpokemon.h"

class PokemonDataBase
{
private:
    QSqlDatabase itsPokemonDataBase ;
public:
    PokemonDataBase();
    bool tryDataBase();
    void closeDatabase();
    void fillARandomTeam(Trainer * trainer);
    void openDataBase();
};

#endif // POKEMONDATABASE_H
