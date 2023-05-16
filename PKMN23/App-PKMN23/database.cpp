#include "database.h"

DataBase::DataBase()
{

}

QSqlDatabase DataBase::initDataBase()
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("pokemon.db");

    if (!Database.open())
    {
        qDebug() << "Error: Connection with database failed";
    }
    else
    {
        qDebug() << "Database: Connection ok";
    }
    return Database;
}

void DataBase::closeDatabase(QSqlDatabase Database)
{
   Database.close();
}

void DataBase::fillARandomTeam(Trainer * trainer, QSqlDatabase Database)
{
    //for(int i = 0 ; i < 6 ; i++)
    //{
        QSqlQuery query("SELECT * FROM POKEMON ORDER BY RANDOM() LIMIT 1;", Database);

        //if(query.next())
        //{
            cout << "test" ;
            QString str = query.value("NAME").toString();
            string name = str.toStdString();
            float height = query.value("HEIGHT").toFloat();
            float weight = query.value("WEIGHT").toFloat();
            unsigned int maxHP = query.value("MAXHP").toUInt();
            unsigned int currentHP = query.value("CURRENTHP").toUInt();
            unsigned int cp = query.value("CP").toUInt();

            QString typeQ = query.value("TYPE").toString();
            string type = typeQ.toStdString();

            cout << type ;

            if(type == "FIRE")
            {
                int nbLegs = query.value("NBLEGS").toInt();
                Pokemon * pokemon = new FirePokemon(name, height, weight, maxHP, currentHP, cp, nbLegs);
                trainer->catchPokemon(pokemon);
                cout << "Ok" ;
            }

            else if(type == "WATER")
            {
                int nbFins = query.value("NBFINS").toInt();
                Pokemon * pokemon = new WaterPokemon(name, height, weight, maxHP, currentHP, cp, nbFins);
                trainer->catchPokemon(pokemon);
                cout << "Ok" ;
            }

            else if(type == "GRASS")
            {
                Pokemon * pokemon = new GrassPokemon(name, height, weight, maxHP, currentHP, cp);
                trainer->catchPokemon(pokemon);
                cout << "Ok" ;
            }

            else if(type == "ELECTRIK")
            {
                int nbLegs = query.value("NBLEGS").toInt();
                int nbWings = query.value("NBWINGS").toInt();
                int intensity = query.value("NBINTENSITY").toInt();
                Pokemon * pokemon = new ElectrikPokemon(name, height, weight, maxHP, currentHP, cp, nbLegs, nbWings, intensity);
                trainer->catchPokemon(pokemon);
                cout << "Ok" ;
            }
            else
            {
                qDebug () << "No pokemon found";
            }
        //}
    //}

}
