#include "pokemondatabase.h"
#include "pokemon.h"
#include "firepokemon.h"
#include "electrikpokemon.h"
#include "grasspokemon.h"
#include "waterpokemon.h"

PokemonDataBase::PokemonDataBase()
{
    itsPokemonDataBase = QSqlDatabase::addDatabase("QSQLITE");
    itsPokemonDataBase.setDatabaseName("../../DataBase/pokemon.db");
}

void PokemonDataBase::openDataBase()
{
    itsPokemonDataBase.open();
}

void PokemonDataBase::closeDatabase()
{
   itsPokemonDataBase.close();
}

bool PokemonDataBase::isOpenDataBase()
{
    return itsPokemonDataBase.isOpen();
}

void PokemonDataBase::fillARandomTeam(Trainer * trainer)
{
    for(int i = 0 ; i < 6 ; i++)
    {
        openDataBase();

        QSqlQuery query("SELECT * FROM POKEMON ORDER BY RANDOM() LIMIT 1;", itsPokemonDataBase);
        if(query.next())
        {
            QString str = query.value("NAME").toString();
            string name = str.toStdString();
            float height = query.value("HEIGHT").toFloat();
            float weight = query.value("WEIGHT").toFloat();
            unsigned int maxHP = query.value("MAXHP").toUInt();
            unsigned int currentHP = query.value("CURRENTHP").toUInt();
            unsigned int cp = query.value("CP").toUInt();

            QString typeQ = query.value("TYPE").toString();
            string type = typeQ.toStdString();

            if(type == "FIRE")
            {
                int nbLegs = query.value("NBLEGS").toInt();
                Pokemon * pokemon = new FirePokemon(name, height, weight, maxHP, currentHP, cp, nbLegs);
                trainer->catchPokemon(pokemon);
            }

            else if(type == "WATER")
            {
                int nbFins = query.value("NBFINS").toInt();
                Pokemon * pokemon = new WaterPokemon(name, height, weight, maxHP, currentHP, cp, nbFins);
                trainer->catchPokemon(pokemon);
            }

            else if(type == "GRASS")
            {
                Pokemon * pokemon = new GrassPokemon(name, height, weight, maxHP, currentHP, cp);
                trainer->catchPokemon(pokemon);
            }

            else if(type == "ELECTRIK")
            {
                int nbLegs = query.value("NBLEGS").toInt();
                int nbWings = query.value("NBWINGS").toInt();
                int intensity = query.value("NBINTENSITY").toInt();
                Pokemon * pokemon = new ElectrikPokemon(name, height, weight, maxHP, currentHP, cp, nbLegs, nbWings, intensity);
                trainer->catchPokemon(pokemon);
            }
            else
            {
                qDebug () << "No pokemon found";
            }
        }
        closeDatabase();
    }
}
