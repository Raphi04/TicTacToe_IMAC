#include "./Board/Board.hpp"
#include "./Player/Player.hpp"
#include "./Gamemode/Gamemode.hpp"

#include <iostream>
#include <array>
#include <algorithm>

#include "terminal_ctrl.hpp"

int main() {
    terminal_ctrl::clear_screen();

    int selected_gamemode {};
    std::array<int, 2> gamemode_selection {1, 2};
    bool valid_gamemode {false};

    std::cout << "Bienvenue dans ce morpion !\n" << std::endl;

    do {
        std::cout << "Choisissez votre mode de jeu :" << std::endl;
        std::cout << "1 - Joueur contre Joueur" << std::endl;
        std::cout << "2 - Joueur contre IA\n" << std::endl;

        std::cin >> selected_gamemode;

        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(255, '\n');
        };
        
        if(std::find(gamemode_selection.begin(), gamemode_selection.end(), selected_gamemode) == gamemode_selection.end()) {
            terminal_ctrl::clear_screen();
            std::cout << "Veuillez choisir un mode de jeu valide !\n" << std::endl;
        } else {
            valid_gamemode = true;
        }
    }while(!valid_gamemode);

    if(selected_gamemode == 1) {
        terminal_ctrl::clear_screen();
        player_vs_player();
    } else {
        terminal_ctrl::clear_screen();
        player_vs_ia();
    }
    
    return 0;
}