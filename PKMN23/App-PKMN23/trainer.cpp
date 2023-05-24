#include "trainer.h"

void Trainer::setFighterPokemon(Pokemon *newFighterPokemon)
{
    //fighterPokemon = nullptr ;
    if(newFighterPokemon->getItsCurrentHP() != 0)
    {
        fighterPokemon = newFighterPokemon;
    }

}

Pokemon *Trainer::getFighterPokemon()
{
    return fighterPokemon;
}

Trainer::Trainer(string name)
{
    itsName = name ;
    itsLevel = 1 ;
    itsPoints = 0 ;
    fighterPokemon = nullptr ;
    itsPokemonTeam = new vector<Pokemon*> ;
}

Trainer::~Trainer()
{
    // Parcourir le vecteur d'équipe de Pokémon
        for (Pokemon * pokemon : *itsPokemonTeam)
        {
            delete pokemon; // Supprimer chaque objet Pokémon
        }

        itsPokemonTeam->clear(); // Effacer tous les pointeurs de Pokémon du vecteur
        delete itsPokemonTeam;   // Supprimer le vecteur lui-même
}

void Trainer::setItsName(const string &newItsName)
{
    itsName = newItsName;
}

void Trainer::catchPokemon(Pokemon* pokemon)
{
    if(itsPokemonTeam->size() < 6)
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
    else
    {
        cout << "Equipe deja complete !" << endl ;
    }


}

float Trainer::getItsAverageSpeed()
{
    float totalAttackSpeed = 0.0;

    // Parcourir chaque Pokémon dans l'équipe du dresseur
    for (Pokemon * pokemon : *itsPokemonTeam)
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
    for (Pokemon *pokemon : *itsPokemonTeam)
    {
        totalHP += pokemon->getItsCurrentHP();
    }

    return totalHP;
}

int Trainer::getItsTotalCP()
{
    int totalCP = 0;

    // Parcourir tous les Pokémon de l'équipe
    for(Pokemon* pokemon : *itsPokemonTeam)
    {
        totalCP += pokemon->getItsCP();
    }
    return totalCP;
}


void Trainer::displayTrainer()
{
    cout << "Dresseur : " << itsName << endl ;
    cout << "Niveau : " << itsLevel << endl ;
    cout << "Points : " << itsPoints << endl ;
    cout << "Nombre de points de vie total de l'equipe : " << getItsTotalTeamHP() << " HP" << endl ;
    cout << "Puissance de combat totale de l'equipe : " << getItsTotalCP() << " CP" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe : " << getItsAverageSpeed() << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type EAU) : " << getItsAverageSpeed("WATER") << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type FIRE): " << getItsAverageSpeed("FIRE") << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type GRASS): " << getItsAverageSpeed("GRASS") << " KM/H" << endl ;
    cout << "Moyenne de la vitesse d'attaque de l'equipe (Type ELECTRIK): " << getItsAverageSpeed("ELECTRIK") << " KM/H" << endl ;
}


void Trainer::attack(Pokemon* myPokemon, Trainer * anOpponentTrainer, Pokemon* anOpponentPokemon)
{
    if(this->isPokemonInTeam(myPokemon) == false || anOpponentTrainer->isPokemonInTeam(anOpponentPokemon) == false)
    {
        return ;
    }

    int damageToOpponent = myPokemon->nbDamage(anOpponentPokemon);
    int damageToMe = anOpponentPokemon->nbDamage(myPokemon);

    // Actualiser le nombre de points de vie de l'adversaire et du dresseur
    myPokemon->attack(anOpponentPokemon);

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

void Trainer::calculateLevel()
{
    if(itsPoints >= 10)
    {
        itsLevel += 1 ;
        itsPoints -= 10 ;
    }
    else if(itsPoints < 0 && itsLevel > 1)
    {
        itsLevel -= 1 ;
        itsPoints += 10 ;
    }

}

float Trainer::getItsAverageSpeed(string itsType)
{
        int count = 0;
        float totalSpeed = 0.0;

        // Parcourir chaque Pokémon dans l'équipe du dresseur
        for (auto * pokemon : *itsPokemonTeam)
        {
            // Vérifier si le Pokémon a le type spécifié
            if (pokemon->getItsType() == itsType)
            {
                totalSpeed += pokemon->getItsSpeed();
                count++;
            }
        }

        // Calculer la moyenne de la vitesse d'attaque pour le type donné
        if (count > 0)
        {
            return totalSpeed / count;
        }
        else
        {
            return 0.0;
        }

}

void Trainer::displayTeam()
{
    for (size_t i = 0; i < itsPokemonTeam->size(); i++)
    {
        cout << "Pokemon #" << i + 1 << ":" << endl;
        (*itsPokemonTeam)[i]->displayPokemon();
        cout << endl;
    }
}

vector<Pokemon*> Trainer::getItsTeam()
{
    return *itsPokemonTeam;
}

int Trainer::getItsLevel()
{
    return itsLevel;
}

int Trainer::getItsPoints()
{
    return itsPoints;
}

void Trainer::removePokemon(Pokemon* pokemon)
{
    if(isPokemonInTeam(pokemon))
    {
        // Parcourir chaque Pokémon dans l'équipe du dresseur
        for (auto it = itsPokemonTeam->begin(); it != itsPokemonTeam->end(); ++it)
        {
            // Vérifier si le Pokémon à supprimer est trouvé dans l'équipe
            if (*it == pokemon)
            {
                // Supprimer le Pokémon de l'équipe
                itsPokemonTeam->erase(it);
                break; // Sortir de la boucle après la suppression
            }
        }
    }
    else return ;
}

bool Trainer::isPokemonInTeam(Pokemon* pokemon)
{
    // Parcourir chaque Pokémon dans l'équipe du dresseur
    for (const auto& p : *itsPokemonTeam)
    {
        // Vérifier si le Pokémon est trouvé dans l'équipe
        if (p == pokemon)
        {
            return true; // Le Pokémon est trouvé, retourner true
        }
    }

    return false; // Le Pokémon n'est pas trouvé, retourner false
}

string Trainer::getItsName()
{
    return itsName;
}

bool Trainer::allPokemonsDead()
{
    for (Pokemon* pokemon : *itsPokemonTeam)
    {
        if (pokemon->getItsCurrentHP() > 0)
        {
            return false; // Au moins un Pokémon est en vie, donc l'équipe n'est pas entièrement morte
        }
    }
    return true; // Tous les Pokémon sont morts
}

Pokemon* Trainer::getNextAlivePokemon()
{
    for (Pokemon* pokemon : *itsPokemonTeam)
    {
        if (pokemon->getItsCurrentHP() > 0)
        {
            return pokemon;
        }
    }

    // Aucun Pokémon en vie trouvé
    return nullptr;
}
