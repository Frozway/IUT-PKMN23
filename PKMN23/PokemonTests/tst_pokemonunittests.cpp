#include <QCOMPARE.h>
#include <QtTest>

// add necessary includes here
#include "../App-PKMN23/pokemon.h"
#include "../App-PKMN23/waterpokemon.h"
#include "../App-PKMN23/grasspokemon.h"
#include "../App-PKMN23/firepokemon.h"
#include "../App-PKMN23/electrikpokemon.h"
#include "qtestcase.h"


class PokemonUnitTests : public QObject
{
    Q_OBJECT

public:
    PokemonUnitTests();
    ~PokemonUnitTests();
    Pokemon * Carapuce ;
    Pokemon * Bulbizarre;
    Pokemon * Salameche;
    Pokemon * Pikachu;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getterAndSetterTest();

};

PokemonUnitTests::PokemonUnitTests()
{
    Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 30, 4);
    Bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 30);
    Salameche = new FirePokemon("Salameche", 0.65, 12, 70, 30, 2);
    Pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 30, 2, 0, 50);
}

PokemonUnitTests::~PokemonUnitTests()
{
    delete Carapuce ;
    delete Bulbizarre ;
    delete Salameche ;
    delete Pikachu ;
}

void PokemonUnitTests::initTestCase()
{
    Pokemon * Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 30, 4);
    Pokemon * Bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 30);
    Pokemon * Salameche = new FirePokemon("Salameche", 0.65, 12, 70, 30, 2);
    Pokemon * Pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 30, 2, 0, 50);

    delete Carapuce ;
    delete Bulbizarre ;
    delete Salameche ;
    delete Pikachu ;
}

void PokemonUnitTests::cleanupTestCase()
{

}

void PokemonUnitTests::getterAndSetterTest()
{
    QCOMPARE(Carapuce->getItsCP() , 30);

    QCOMPARE(Bulbizarre->getItsHP(), 70);

    QCOMPARE(Salameche->getItsType(), "FEU");

    Pikachu->setItsHP(80);
    QCOMPARE(Pikachu->getItsHP(), 80);
}

QTEST_APPLESS_MAIN(PokemonUnitTests)

#include "tst_pokemonunittests.moc"
