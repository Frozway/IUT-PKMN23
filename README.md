---

Retrouver tous les détails dans le wiki et la [documentation ici](https://tlefranc.forge-pages.iut-larochelle.fr/pkmn23/annotated.html)

## Introduction
> Bienvenue sur la page wiki dédiée au projet Pokémon (PKMN23) ! Cette ressource est conçue pour fournir une documentation complète sur l'ensemble du processus de développement du jeu de cartes Pokémon. Que vous soyez un membre de l'équipe de développement, un contributeur ou simplement curieux d'en apprendre davantage sur les coulisses du projet, cette page est l'endroit idéal pour accéder à toutes les informations nécessaires.

<br> L'objectif de cette documentation est de vous guider à travers les différentes phases du projet Pokémon, en commençant par l'analyse et la conception, jusqu'à la mise en œuvre finale du jeu. Vous trouverez ici des explications détaillées sur les choix de conception, les fonctionnalités principales, ainsi que les différentes étapes du développement.

Le Cahier des charges du projet Pokémon vous permettra de plonger dans les spécifications et les exigences du jeu. Vous découvrirez une description complète des fonctionnalités attendues, des règles du jeu et des caractéristiques des Pokémon et des dresseurs. Cette étape est cruciale pour établir une base solide avant de passer à la conception.

La section d'analyse et conception vous présentera les différents diagrammes utilisés pour représenter la structure du projet. Vous trouverez des diagrammes de classes, des diagrammes de séquence et un diagramme de cas d'utilisation, qui vous aideront à visualiser les relations entre les différentes entités du jeu et à comprendre leur fonctionnement.

## Cahier des charges

> [Page détaillé du cahier des charges](Cahier des charges)

Le cahier des charges de ce projet a pour objectif de définir les spécifications et les fonctionnalités de mon application Pokémon (PKMN23), ainsi que les règles du jeu et les caractéristiques des Pokémon et des dresseurs. Tout en sachant que ce jeu est conçu pour offrir une expérience immersive et captivante aux joueurs, en leur permettant de devenir de véritables dresseurs de Pokémon et de vivre des aventures passionnantes dans le monde Pokémon.

## Versions

> [Page détaillé avec les versions](Versions du jeu)

Dans le cadre du projet Pokémon, une version est une étape spécifique du développement qui regroupe un ensemble de fonctionnalités et d'améliorations mises en œuvre à un moment précis. Chaque version est identifiée par un numéro qui permet de suivre l'évolution du projet au fil du temps. La version 1.0 marque la toute première version jouable du jeu.

La version 1.0 est le point de départ du projet Pokémon, où les fonctionnalités essentielles sont introduites pour offrir une expérience de jeu de base aux joueurs. Elle peut inclure des éléments tels que la création et la gestion des dresseurs, l'attrapage et la gestion des Pokémon, les combats entre les dresseurs, les interactions avec les Pokémon et les mécanismes de progression.

Au fur et à mesure de l'avancement du projet, de nouvelles versions seront développées, apportant des améliorations, des correctifs de bugs, des fonctionnalités supplémentaires et des ajouts au gameplay. Chaque nouvelle version représentera une avancée significative dans le développement du jeu, offrant aux joueurs une expérience de jeu de plus en plus riche et complète.

## Analyse et Conception

> [Page détaillé avec les diagrammes](Analyse et Conception)

### Diagramme des cas d'utilisation
Un diagramme de cas d'utilisation est une représentation graphique des interactions entre les acteurs (utilisateurs ou systèmes externes) et le système lui-même. Il met en évidence les fonctionnalités principales du système et montre comment les acteurs interagissent avec ces fonctionnalités.

### Diagramme de classes
Le diagramme de classe ci-dessous représente la structure et les relations des différentes classes du système "Pokemon". Il décrit les entités principales telles que les Pokémon, les dresseurs et la base de données des Pokémon. Le système permet aux utilisateurs de jouer à des combats de Pokémon dans différents modes (Joueur contre Joueur, Joueur contre IA, IA contre IA) en utilisant une interface utilisateur. Les dresseurs peuvent constituer des équipes de Pokémon, combattre et échanger des Pokémon entre eux.

### Diagrammes de séquence 
Un diagramme de séquence est un outil de modélisation qui montre l'ordre des interactions entre les objets d'un système pendant l'exécution d'un scénario spécifique. Il met en évidence les messages échangés entre les objets et l'ordre dans lequel ces messages sont transmis.

Le modèle MVC (Modèle-Vue-Contrôleur) quant à lui, est un motif d'architecture de conception largement utilisé dans le développement logiciel pour séparer la logique métier (Modèle) de la présentation (Vue) et de la gestion des interactions (Contrôleur).
