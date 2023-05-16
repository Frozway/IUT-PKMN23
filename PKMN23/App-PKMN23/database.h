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

class DataBase
{
public:
    DataBase();
    QSqlDatabase initDataBase();
    void closeDatabase(QSqlDatabase Database);
    void fillARandomTeam(Trainer * trainer, QSqlDatabase Database);
};

#endif // DATABASE_H
