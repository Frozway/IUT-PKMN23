#include "trainer.h"

int Trainer::itsLevel = 1;
int Trainer::itsPoints = 0;

Trainer::Trainer(string name)
{
    itsName = name ;
    itsPokemonTeam = new vector<Pokemon*> ;
}

void Trainer::catchPokemon(Pokemon* pokemon)
{
    itsPokemonTeam->push_back(pokemon);
    itsPoints += 1 ;

    // Trier l'équipe dans l'ordre naturel par type et par PC

    sort(itsPokemonTeam->begin(), itsPokemonTeam->end(), [](Pokemon* p1, Pokemon* p2)
    {
        // Trier par type (ordre alphabétique)
        if (p1->getItsType() != p2->getItsType()) {
            return p1->getItsType() < p2->getItsType();
        }
        // Trier par PC (puissance de combat)
        return p1->getItsCP() < p2->getItsCP();
    });
}

float Trainer::getItsAverageSpeed()
{
    float totalAttackSpeed = 0.0;

    // Parcourir chaque Pokémon dans l'équipe du dresseur
    for (auto& pokemon : *itsPokemonTeam)
    {
        totalAttackSpeed += pokemon->getItsSpeed();
    }

    // Calculer la moyenne de la vitesse d'attaque
    if (itsPokemonTeam->size() > 0)
    {
        return totalAttackSpeed / itsPokemonTeam->size();
    }
    else
    {
        return 0.0;
    }
}

int Trainer::getItsTotalTeamHP()
{
    int totalHP = 0;

    // Parcourir chaque Pokémon dans l'équipe du dresseur
    for (const auto& pokemon : *itsPokemonTeam)
    {
        totalHP += pokemon->getItsCurrentHP();
    }

    return totalHP;
}

int Trainer::getItsTotalCP()
{
    int totalCP = 0;

    // Parcourir tous les Pokémon de l'équipe
    for (const auto& pokemon : *itsPokemonTeam)
    {
        totalCP += pokemon->getItsCP();
    }

    return totalCP;
}


void Trainer::displayTrainer()
{
    cout << "Dresseur : " << itsName << endl;
    cout << "Niveau : " << itsLevel << endl;
    cout << "Points : " << itsPoints << endl;
    cout << "Nombre de points de vie total de l'équipe : " << getItsTotalTeamHP() << endl;
    cout << "Puissance de combat totale de l'équipe : " << getItsTotalCP() << endl;
    cout << "Moyenne de la vitesse d'attaque de l'équipe : " << getItsAverageSpeed() << endl;
}

bool Trainer::operator<(const Trainer& anOpponent)
{

    if (this->getItsLevel() != anOpponent.getItsLevel())
    {
        return this->getItsLevel() < anOpponent.getItsLevel();
    }

    // Comparaison basée sur les caractéristiques de l'équipe de Pokémon
    // ... Ajoutez ici votre logique de comparaison en fonction des critères spécifiés dans le cahier des charges ...

    // Par défaut, retourne false si les dresseurs ont des niveaux égaux et des équipes de Pokémon similaires
    return false;
}

void Trainer::attack(Trainer* anOpponentTrainer, Pokemon* myPokemon, Pokemon* anOpponentPokemon)
{
    int damageToOpponent = myPokemon->nbDamage(anOpponentPokemon);
    int damageToMe = anOpponentPokemon->nbDamage(myPokemon);

    // Actualiser le nombre de points de vie de l'adversaire et du dresseur
    myPokemon->attack(anOpponentPokemon);
    //anOpponentPokemon->setItsHP(anOpponentPokemon->getItsCurrentHP() - damageToOpponent);
    //myPokemon->setItsHP(myPokemon->getItsCurrentHP() - damageToMe);

    // Vérifier si le Pokémon de l'adversaire est mis KO en un coup
    if (anOpponentPokemon->getItsCurrentHP() <= 0)
    {
        // Ajouter les points pour mettre KO le Pokémon de l'adversaire
        itsPoints += 3;
        anOpponentTrainer->setItsPoints(itsPoints-3); // !!!!!!!!!!!!!!!!!!!!!!!!! Vérifier que si le trainer arrive a 0 il descende d'un niveau
    }

    // Vérifier si mon Pokémon est mis KO en un coup
    if (myPokemon->getItsCurrentHP() <= 0)
    {
        myPokemon->setItsHP(0);
        // Retirer les points pour avoir mon Pokémon mis KO en un coup
        itsPoints -= 3;
    }

    // Vérifier si j'ai infligé plus de dégâts que j'ai reçu
    if (damageToOpponent > damageToMe)
    {
        // Ajouter les points pour avoir infligé plus de dégâts à l'adversaire
        itsPoints += 2;
    }
}

void Trainer::setItsPoints(int newItsPoints)
{
    itsPoints = newItsPoints;
}

