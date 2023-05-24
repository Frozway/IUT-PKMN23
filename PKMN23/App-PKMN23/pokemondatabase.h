/**
 * @file pokemondatabase.h
 *
 * @brief The PokemonDataBase class represents a database for managing Pokemon information.
 *
 * The class provides functionality to open, close, and interact with a Pokemon database.
 * It allows adding and retrieving Pokemon data from the database.
 * @version 0.3
 * @author Thibaut LEFRANCOIS
 * @date May 2023
 */

#ifndef POKEMONDATABASE_H
#define POKEMONDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

#include "trainer.h"


/**
 * @class PokemonDataBase
 * @brief The PokemonDataBase class represents a database for managing Pokemon information.
 *
 * The class provides functionality to open, close, and interact with a Pokemon database.
 * It allows adding and retrieving Pokemon data from the database.
 */
class PokemonDataBase
{
private:
    QSqlDatabase itsPokemonDataBase; /**< The database connection object */

public:
    /**
     * @brief Constructs a new PokemonDataBase object.
     *
     * This constructor initializes the Pokemon database object.
     */
    PokemonDataBase();

    /**
     * @brief Checks if the Pokemon database is open.
     *
     * This method checks if the Pokemon database is open and returns the status.
     *
     * @return true if the Pokemon database is open, false otherwise.
     */
    bool isOpenDataBase();

    /**
     * @brief Opens the Pokemon database.
     *
     * This method opens the connection to the Pokemon database.
     */
    void openDataBase();

    /**
     * @brief Closes the Pokemon database.
     *
     * This method closes the connection to the Pokemon database.
     */
    void closeDatabase();

    /**
     * @brief Fills a random team for a Trainer.
     *
     * This method generates a random team of Pokemon for a given Trainer by retrieving
     * Pokemon data from the database.
     *
     * @param trainer A pointer to the Trainer for which to generate the random team.
     */
    void fillARandomTeam(Trainer* trainer);
};

#endif // POKEMONDATABASE_H
