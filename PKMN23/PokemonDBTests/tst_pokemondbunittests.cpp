#include <QtTest>

// add necessary includes here
#include "../App-PKMN23/pokemondatabase.h"
#include "../App-PKMN23/trainer.h"
#include "../App-PKMN23/pokemon.h"
#include "../App-PKMN23/firepokemon.h"
#include "../App-PKMN23/electrikpokemon.h"
#include "../App-PKMN23/grasspokemon.h"
#include "../App-PKMN23/waterpokemon.h"

class PokemonDBUnitTests : public QObject
{
    Q_OBJECT

public:
    PokemonDBUnitTests();
    ~PokemonDBUnitTests();
    PokemonDataBase * Database ;
    Trainer * trainer1 ;

private slots:
    void database_manipulation_tests();

};

PokemonDBUnitTests::PokemonDBUnitTests()
{
    Database = new PokemonDataBase();
    trainer1 = new Trainer("Sacha");
}

PokemonDBUnitTests::~PokemonDBUnitTests()
{
    delete Database ;
    delete trainer1 ;
}

void PokemonDBUnitTests::database_manipulation_tests()
{
    //Vérifier l'ouverture & fermeture de la base de donnée pokémon
    Database->openDataBase();
    QCOMPARE(Database->isOpenDataBase(), true);
    Database->closeDatabase();
    QCOMPARE(Database->isOpenDataBase(), false);

    //Vérifier que le remplissage aléatoire d'une équipe se fait correctement
    Database->fillARandomTeam(trainer1);
    QCOMPARE(trainer1->getItsTeam().empty(), false); //Vérifier que l'équipe n'est pas vide
    QCOMPARE(trainer1->getItsPoints(), 6); //Vérifier qu'il a bien reçu 6 pokémon en comptant son nombre de points qui représente au départ le nb de poké
}

QTEST_APPLESS_MAIN(PokemonDBUnitTests)

#include "tst_pokemondbunittests.moc"
