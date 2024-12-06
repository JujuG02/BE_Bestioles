# BE_Bestioles

# Simulation d'un Écosystème - Aquarium

## Description du Projet
Ce projet consiste à simuler un écosystème d'un aquarium peuplé de bestioles. Chaque bestiole se déplace dans l'aquarium, interagit avec son environnement et peut évoluer au fil du temps. Le projet utilise des design patterns pour structurer le code et faciliter les évolutions futures.

## Fonctionnalités
- **Déplacement des bestioles** : Chaque bestiole se déplace avec une vitesse et une direction aléatoires ;
- **Naissance et Mort** : Les bestioles peuvent naître spontanément ou suite à un événement extérieur, et meurent après un certain temps ou en cas de collision ;
- **Clonage** : Les bestioles peuvent se cloner, augmentant ainsi leur population ;
- **Capteurs et Accessoires** : Les bestioles peuvent être équipées de capteurs (yeux, oreilles) et d'accessoires (nageoires, carapace, camouflage) pour interagir avec leur environnement ;

## Structure du Code

- `main.cpp` : Point d'entrée du programme.
- `Bestiole.h` / `Bestiole.cpp` : Définition et implémentation de la classe Bestiole.
- `BestioleCreator.h` / `BestioleCreator.cpp` : Définition et implémentation de la classe de création des bestioles.
- `Aquarium.h` / `Aquarium.cpp` : Définition et implémentation de la classe Aquarium.
- `Capteurs.h` / `Capteurs.cpp` : Définition et implémentation des capteurs.
- `Accessoires.h` / `Accessoires.cpp` : Définition et implémentation des accessoires.
- `Camouflage.h` / `Camouflage.cpp` : Définition et implémentation de l'accessoire de camouflage.
- `Gregaire.h` / `Gregaire.cpp` : Définition et implémentation de la classe représentant le comportement grégaire.
- `Kamikaze.h` / `Kamikaze.cpp` : Définition et implémentation de la classe représentant le comportement kamikaze.
- `Milieu.h` / `Milieu.cpp` : Définition et implémentation de la classe Milieu, qui représente l'environnement de l'aquarium.
- `Nageoire.h` / `Nageoire.cpp` : Définition et implémentation de l'accessoire de nageoire.
- `Peureuse.h` / `Peureuse.cpp` : Définition et implémentation de la classe représentant le comportement peureux.
- `Prevoyante.h` / `Prevoyante.cpp` : Définition et implémentation de la classe représentant le comportement prévoyant.
- `Sensor.h` / `Sensor.cpp` : Définition et implémentation des capteurs sensoriels (oreilles, yeux...) pour les bestioles.
- `Carapace.h` / `Carapace.cpp` : Définition et implémentation de la classe représentant l'accessoire de carapace.
- `Clone.h` : Définition de l'interface de clonage pour les bestioles.
- `Creator.h` : Définition de l'interface de création pour les bestioles.
- `Decorator.h` : Définition de la classe de décoration pour ajouter des fonctionnalités aux bestioles.

## Instructions d'Installation
1. Clonez le dépôt :
   ```bash
   git clone https://github.com/JujuG02/BE_Bestioles

2. Compilez le projet :
   ```bash
   cd BE_Bestioles/src/
   make

3. Exécutez le programme :
   ```bash
   ./main

## Élèves

Alexia Caravaca
Élodie Bottin
Julien Abraul Guilherme
Loïc Derrien
Thomas Georgi


