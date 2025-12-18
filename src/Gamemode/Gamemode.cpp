#include "./Gamemode.hpp"
#include "../Player/Player.hpp"
#include "../Board/Board.hpp"

#include <array>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <algorithm>

#include "terminal_ctrl.hpp"

void player_vs_player() {
    //Création des joueurs
    std::pair<Player, Player> const players = create_player(false);
    Player const& player1 = players.first;
    Player const& player2 = players.second;

    //Variables de la partie
    int turn {1};
    std::array<std::string, 9> board {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    bool victory {false};
        
    //Choix du premier joueur
    std::srand(std::time(nullptr));
    int player_playing_number = std::rand() % 2 + 1;
    Player const* player_playing {};

    //Déroulement de la partie
    do {
        terminal_ctrl::clear_screen();

        if(player_playing_number == 1) {
            player_playing = &player1;
        } else {
            player_playing = &player2;
        }

        std::cout << "\nDebut du tour " << turn << " ! (" << player_playing->name << ")\n" << std::endl;
        
        draw_game_board(board);

        check_valid_cell(board, *player_playing);
        
        if(check_victory(board, *player_playing)) {
            victory = true;
        } else {
            player_playing_number = player_playing_number == 1 ? 2 : 1;
            turn++;
        };

    } while (!victory && turn != 10);

    if(victory) {
        terminal_ctrl::clear_screen();
        draw_game_board(board);
        std::cout << "\n" << player_playing->name << " a gagne la partie !" << std::endl;
    } else {
        terminal_ctrl::clear_screen();
        draw_game_board(board);
        std::cout << "Votre partie est une egalite !" << std::endl;
    }
};

void player_vs_ia() {
    std::pair<Player, Player> const players = create_player(true);
    
    Player const& player1 = players.first;
    Player const& player2 = players.second;

    //Variables de la partie
    int turn {1};
    std::array<std::string, 9> board {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    bool victory {false};
        
    //Choix du premier joueur
    std::srand(std::time(nullptr));
    int player_playing_number = std::rand() % 2 + 1;
    Player const* player_playing {};

    //Déroulement de la partie
    do {
        terminal_ctrl::clear_screen();

        if(player_playing_number == 1) {
            player_playing = &player1;
        } else {
            player_playing = &player2;
        }

        std::cout << "\nDebut du tour " << turn << " ! (" << player_playing->name << ")\n" << std::endl;
        
        draw_game_board(board);

        if(player_playing->is_ai) {
            ia_choosing_cell(board, player1, player2);
        } else {
            check_valid_cell(board, *player_playing);
        }
        
        if(check_victory(board, *player_playing)) {
            victory = true;
        } else {
            player_playing_number = player_playing_number == 1 ? 2 : 1;
            turn++;
        };

    } while (!victory && turn != 10);

    if(victory) {
        terminal_ctrl::clear_screen();
        draw_game_board(board);
        std::cout << "\n" << player_playing->name << " a gagne la partie !" << std::endl;
    } else {
        terminal_ctrl::clear_screen();
        draw_game_board(board);
        std::cout << "Votre partie est une egalite !" << std::endl;
    }
};

