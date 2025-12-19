# Morpion - Raphael CADETE

Vous retrouverez dans ce document des informations sur la réalisation de ce projet.

## Librairie et système d'exploitation

Le projet a été réalisé avec les fonctionnalités de base de C++, la seule librairie qui a été ajoutée est celle qui nettoie le terminal.

Ce morpion a uniquement été testé sur Windows 11.

## Organisation des fichiers

J'ai séparé mes fichiers en trois catégories : **_Player_**, **_Gamemode_** et **_Board_**. Le fichier **_main.cpp_** n'appartient à aucune de ces catégories.

- **_main.cpp_** contient évidemment le démarrage de mon programme, soit la sélection du mode de jeu.

- Le dossier **_Player_** contient les fichiers **_player.hpp_** et **_player.cpp_**. C'est ici que sont définis ma structure **_Player_** et ma fonction **_create_player()_**. Concrètement, c'est ici que sont gérés tout ce qui touche aux joueurs.

- Le dossier **_Gamemode_** contient les fichiers **_gamemode.hpp_** et **_gamemode.cpp_**. C'est ici que sont définis le fonctionnement des deux modes de jeu : **_player_vs_player_()** et **_player_vs_ai()_**. Concrètement, c'est ici que sont gérer tout ce qui touche à la gestion du déroulement de la partie.

- Le dossier **_Board_** contient les fichiers **_board.hpp_** et **_board.cpp_**. C'est ici que sont définis le fonctionnement des actions réalisées sur le plateau de jeu : **_draw_game_board()_**, **_check_valid_cell()_**, **_ai_choosing_cell()_** et **_check_victory()_**. Concrètement, c'est ici que sont gérer toutes les actions des joueurs et ce qui touche à la gestion du plateau de jeu.

## Améliorations

J'ai décidé d'améliorer l'IA de façon à ce qu'elle joue aléatoirement sauf quand elle risque de perdre ou quand elle peut gagner. Pour cela, je lui fais regarder les cases vides du plateau et, pour chacune d'entre elle, je lui fais vérifier si en plaçant le symbole du joueur 1 ou 2, une victoire se déclare. Ainsi, elle bloque et attaque et le cas échéant, elle joue aléatoirement.

## Problèmes et solutions

J'avais rencontré un problème avec l'utilisation de la librairie permettant de nettoyer le terminal, mais après avoir demander de l'aide à Jules en TD, j'ai réussi à l'utiliser.

Dans ma boucle for qui affiche le plateau de jeu, j'avais en tant que neuvième case, le nom du joueur 1. Cela était du à un débordement du tableau puisque j'ai mal défini l'initialisation de ma boucle for (i = 1 au lieu de 0).

Quand je développais l'amélioration de l'IA, elle était théoriquement fonctionnelle mais de temps en temps, elle jouait sur une case déjà prise.
Concrètement je luis fais tirer un nombre aléatoire entre 0 et la taille du tableau contenant les index des cases vides et je luis fais joueur le nombre tirer. Après une longue recherche avec le debugger, j'ai fini par comprendre que je luis faisait jouer le mauvais index. En effet, si je tire par exemple 1, alors je lui faisait jouer la case 2 dû plateau, sauf que j'aurais du lui faire jouer sur la case contenu à l'index 1 du tableau vide.
