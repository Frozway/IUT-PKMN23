#include <QtTest>

// add necessary includes here
#include "../App-PKMN23/gamemaker.h"
#include "../App-PKMN23/ui.h"
#include "../App-PKMN23/pokemon.h"
#include "../App-PKMN23/trainer.h"
#include "../App-PKMN23/pokemondatabase.h"
#include "../App-PKMN23/electrikpokemon.h"
#include "../App-PKMN23/firepokemon.h"
#include "../App-PKMN23/waterpokemon.h"
#include "../App-PKMN23/grasspokemon.h"


class GameUnitTests : public QObject
{
    Q_OBJECT

public:
    GameUnitTests();
    ~GameUnitTests();
    GameMaker * Game ; /**< The Game object */
    UI * itsUserInterface ; /**< The user interface object */
    PokemonDataBase * itsPokemonDB ; /**< The Pokemon database object */
    Trainer * itsTrainer1 ; /**< Pointer to the first trainer */
    Trainer * itsTrainer2 ; /**< Pointer to the second trainer */
    Trainer * itsFirstTrainer; /**< Pointer to the first trainer in a fight */
    Trainer * itsSecondTrainer; /**< Pointer to the second trainer in a fight */

private slots:
    void initTestCase();
    void cleanupTestCase();
    void transferTest();
    void boolTest();

};

GameUnitTests::GameUnitTests()
{
    Game = new GameMaker();
    itsUserInterface = new UI();
    itsPokemonDB = new PokemonDataBase();
    itsTrainer1 = new Trainer("Joueur 1");
    itsTrainer2 = new Trainer("Joueur 2");
    itsFirstTrainer = new Trainer("itsFirstTrainer");
    itsSecondTrainer = new Trainer("itsSecondTrainer");
}

GameUnitTests::~GameUnitTests()
{
    delete Game ;
}

void GameUnitTests::initTestCase()
{
    Game->setItsUserInterface(itsUserInterface);
    Game->setItsPokemonDB(itsPokemonDB);
    Game->setItsTrainer1(itsTrainer1);
    Game->setItsTrainer2(itsTrainer2);
    Game->setItsFirstTrainer(itsFirstTrainer);
    Game->setItsSecondTrainer(itsSecondTrainer);
}

void GameUnitTests::cleanupTestCase()
{

}

void GameUnitTests::transferTest()
{
    initTestCase();

    Game->getItsPokemonDB()->fillARandomTeam(itsTrainer1);
    Pokemon * test = itsTrainer1->getItsTeam()[0];
    Game->transferPokemon(itsTrainer1, itsTrainer1->getItsTeam()[0]);
    QCOMPARE(test == itsTrainer1->getItsTeam()[0], false);

}


void GameUnitTests::boolTest()
{
    initTestCase();
    Game->getItsPokemonDB()->fillARandomTeam(itsTrainer1);
    Game->getItsPokemonDB()->fillARandomTeam(itsTrainer2);

    //Imaginons que le pokemon attaquant est celui à l'indice 0 et qu'il s'est fait mettre KO
    itsTrainer1->getItsTeam()[0]->setItsHP(0);

    //Vérifions si le jeu considère le combat terminé
    QCOMPARE(Game->isFightFinished(itsTrainer1->getItsTeam()[0], itsTrainer2->getItsTeam()[0]), true);

    //Imaginons maintenant que toute son équipe est KO
    itsTrainer1->getItsTeam()[1]->setItsHP(0);
    itsTrainer1->getItsTeam()[2]->setItsHP(0);
    itsTrainer1->getItsTeam()[3]->setItsHP(0);
    itsTrainer1->getItsTeam()[4]->setItsHP(0);
    itsTrainer1->getItsTeam()[5]->setItsHP(0);

    //Vérifié si le jeu considère que la partie est terminé
    QCOMPARE(Game->isGameFinished(itsTrainer1, itsTrainer2), true);
}

QTEST_APPLESS_MAIN(GameUnitTests)

#include "tst_gameunittests.moc"
