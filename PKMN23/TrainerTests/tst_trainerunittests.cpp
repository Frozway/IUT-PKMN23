#include <QtTest>
#include <qcompare.h>
#include "qtestcase.h"

// add necessary includes here
#include "../App-PKMN23/trainer.h"
#include "../App-PKMN23/pokemon.h"
#include "../App-PKMN23/waterpokemon.h"
#include "../App-PKMN23/grasspokemon.h"
#include "../App-PKMN23/firepokemon.h"
#include "../App-PKMN23/electrikpokemon.h"

class TrainerUnitTests : public QObject
{
    Q_OBJECT

public:
    TrainerUnitTests();
    ~TrainerUnitTests();
    Trainer * Sacha ;
    Trainer * Pierre ;
    Pokemon* carapuce ;
    Pokemon* bulbizarre ;
    Pokemon* salameche ;
    Pokemon* pikachu ;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void catchAndRemovePokemon_test();
    void attackPokemonByTrainer_test();
    void testPokemonInTeam();
    void testLevel();
    void testGetter();

};

TrainerUnitTests::TrainerUnitTests()
{
    Sacha = new Trainer("Sacha");
    Pierre = new Trainer("Pierre");

    carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 70, 30, 4);
    bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 70, 30);
    salameche = new FirePokemon("Salameche", 0.65, 12, 70, 70, 30, 2);
    pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 70, 30, 2, 0, 50);
}

TrainerUnitTests::~TrainerUnitTests()
{
//    delete Sacha ;
//    delete Pierre ;
}

void TrainerUnitTests::initTestCase()
{
    Sacha = new Trainer("Sacha");
    Pierre = new Trainer("Pierre");
    carapuce = new WaterPokemon("Carapuce", 0.81, 12, 70, 70, 30, 4);
    bulbizarre = new GrassPokemon("Bulbizarre", 0.7, 15, 70, 70, 30);
    salameche = new FirePokemon("Salameche", 0.65, 12, 70, 70, 30, 2);
    pikachu = new ElectrikPokemon("Pikachu", 0.4, 6, 70, 70, 30, 2, 0, 50);
}

void TrainerUnitTests::cleanupTestCase()
{
    delete Sacha ;
    delete Pierre ;
}

void TrainerUnitTests::catchAndRemovePokemon_test()
{
    initTestCase();

    //Ajout de pokémon et vérifier si il se retrouve bien dans l'équipe du dresseur
    Sacha->catchPokemon(carapuce);
    QCOMPARE(Sacha->getItsTeam()[0], carapuce);

    //Retrait du pokemon et vérifier si maintenant la liste est vide
    Sacha->removePokemon(carapuce);
    QCOMPARE(Sacha->getItsTeam().empty(), true);

    cleanupTestCase();
}

void TrainerUnitTests::attackPokemonByTrainer_test()
{
    initTestCase();

    //Ajout de pokemon pour combattre
    Sacha->catchPokemon(carapuce);
    Pierre->catchPokemon(salameche);

    //Mise à 0 des points pour tester l'ajout de 2 points comme carapuce fait plus de dégats
    Sacha->setItsPoints(0);
    Sacha->attack(carapuce, Pierre, salameche);
    QCOMPARE(Sacha->getItsPoints(), 2);

    //Test de si l'attaque lui à bien enlevé 2 fois les CP de carapuce
    int expectedSalamecheHP = (Pierre->getItsTeam()[0]->getItsMaxHP()) - (Sacha->getItsTeam()[0]->nbDamage(salameche)) ;
    int actualSalamecheHP = Pierre->getItsTeam()[0]->getItsCurrentHP();

    QCOMPARE(actualSalamecheHP, expectedSalamecheHP);

    //Test de si le pokemon descend en dessous de 0 HP, son nombre de HP est remis à jour à 0 et que le pokémon qui attaque est soigné
    Pierre->attack(salameche, Sacha, carapuce); //Infligé des dégats pour essayer le soin par la suite=
    Sacha->attack(carapuce, Pierre, salameche); //Infligé des dégats emmenant les HP < 0

    int expectedCarapuceHP = Sacha->getItsTeam()[0]->getItsMaxHP();
    int actualCarapuceHP = Sacha->getItsTeam()[0]->getItsCurrentHP();

    QCOMPARE(Pierre->getItsTeam()[0]->getItsCurrentHP(), 0); //Vérifier que Salamèche est à 0 HP
    QCOMPARE(actualCarapuceHP, expectedCarapuceHP); //Vérifier que carapuce à été soigné

    cleanupTestCase();
}

void TrainerUnitTests::testPokemonInTeam()
{
    initTestCase();
    Sacha->catchPokemon(carapuce);
    //Tester la recherche de pokemon dans une équipe d'un dresseur
    QCOMPARE(Sacha->isPokemonInTeam(carapuce), true) ;
    cleanupTestCase();
}

void TrainerUnitTests::testLevel()
{
    initTestCase();

    Sacha->setItsPoints(0);
    Sacha->setItsPoints(10);
    Sacha->calculateLevel();
    QCOMPARE(Sacha->getItsLevel(), 2);
    QCOMPARE(Sacha->getItsPoints(), 0);

    cleanupTestCase();
}

void TrainerUnitTests::testGetter()
{
    initTestCase();

    //Vérifie le nombre total d'HP de l'équipe de sacha (carapuce (70) + salameche (70))
    Sacha->catchPokemon(salameche);
    Sacha->catchPokemon(carapuce);
    QCOMPARE(Sacha->getItsTotalTeamHP(), 140);

    QCOMPARE(Sacha->getItsTotalCP(), 60);
}

QTEST_APPLESS_MAIN(TrainerUnitTests)

#include "tst_trainerunittests.moc"
