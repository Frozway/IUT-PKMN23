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
    void attackTest();

};

PokemonUnitTests::PokemonUnitTests()
{
    Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 70, 30, 4);
    Bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 70, 30);
    Salameche = new FirePokemon("Salameche", 0.65, 12, 70, 70, 30, 2);
    Pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 70, 30, 2, 0, 50);
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
    Pokemon * Carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 70, 30, 4);
    Pokemon * Bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 70, 30);
    Pokemon * Salameche = new FirePokemon("Salameche", 0.65, 12, 70, 70, 30, 2);
    Pokemon * Pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 70, 30, 2, 0, 50);

    delete Carapuce ;
    delete Bulbizarre ;
    delete Salameche ;
    delete Pikachu ;
}

void PokemonUnitTests::cleanupTestCase()
{

}

void PokemonUnitTests::attackTest()
{
    // Test de l'attaque de Carapuce sur Salameche
    Carapuce->attack(Salameche);

    // Vérification que la santé actuelle de Salameche est de 10 après l'attaque
    QCOMPARE(Salameche->getItsCurrentHP(), 10);

    // Vérification que les dégâts infligés par Salameche à Bulbizarre sont corrects
    // Les dégâts sont calculés en multipliant le CP de Salameche par 2
    QCOMPARE(Salameche->nbDamage(Bulbizarre), 2 * (Salameche->getItsCP()));
}

void PokemonUnitTests::getterAndSetterTest()
{
    // Vérification du getter de l'attribut itsCP de Carapuce
    QCOMPARE(Carapuce->getItsCP(), 30);

    // Vérification du getter de l'attribut itsCurrentHP de Bulbizarre
    QCOMPARE(Bulbizarre->getItsCurrentHP(), 70);

    // Vérification du getter de l'attribut itsType de Salameche
    QCOMPARE(Salameche->getItsType(), "FIRE");

    // Modification de la santé actuelle de Pikachu à 80 à l'aide du setter
    Pikachu->setItsHP(80);

    // Vérification que la santé actuelle de Pikachu est bien de 80
    QCOMPARE(Pikachu->getItsCurrentHP(), 80);
}




QTEST_APPLESS_MAIN(PokemonUnitTests)

#include "tst_pokemonunittests.moc"
