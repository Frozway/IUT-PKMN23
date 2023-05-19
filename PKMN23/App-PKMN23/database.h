#ifndef DATABASE_H
#define DATABASE_H

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

class Database
{
private:
    QSqlDatabase itsPokemonDataBase ;
    QSqlDatabase itsSaveDataBase ;
public:
    Database();
    bool tryDataBase();
    void closeDatabase();
    void fillARandomTeam(Trainer * trainer);
    void openDataBase();
};

#endif // DATABASE_H
