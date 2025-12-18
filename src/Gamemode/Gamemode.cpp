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

    //Déroulement de la partie
    int turn {1};
    std::array<std::string, 9> board {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    std::array<int, 9> const cell_numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool valid_cell_number {false};
    
    bool victory {false};

    std::srand(std::time(nullptr));
    int player_playing_number = std::rand() % 2 + 1;
    Player const* player_playing {};
    int player_playing_selected_cell {};
    
    do {
        terminal_ctrl::clear_screen();
        valid_cell_number = false;

        if(player_playing_number == 1) {
            player_playing = &player1;
        } else {
            player_playing = &player2;
        }

        std::cout << "\nDebut du tour " << turn << " ! (" << player_playing->name << ")\n" << std::endl;
        
        draw_game_board(board);

        do {
            std::cout << "\nSelectioner une case : ";
            std::cin >> player_playing_selected_cell;
    
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(255, '\n');
            };
            
            if(std::find(cell_numbers.begin(), cell_numbers.end(), player_playing_selected_cell) == cell_numbers.end()) {
                std::cout << "Veuillez choisir une case valide !\n" << std::endl;
            } else {
                if(board[player_playing_selected_cell - 1] != "X" && board[player_playing_selected_cell - 1] != "O") {
                    board[player_playing_selected_cell - 1] = player_playing->symbole;
                    valid_cell_number = true;
                } else {
                    std::cout << "Veuillez choisir une case vide !\n" << std::endl;
                }
            }
        }while(!valid_cell_number);

        player_playing_number = player_playing_number == 1 ? 2 : 1;
        turn++;
    } while (!victory && turn != 10);

    if(victory) {

    } else {
        std::cout << "Votre partie est une egalite !" << std::endl;
    }
};

void player_vs_ia() {
    std::pair<Player, Player> const players = create_player(true);
    
    Player const& player1 = players.first;
    Player const& player2 = players.second;

    std::cout << "\nplayer 1 name: " << player1.name << " player 1 symbole : " << player1.symbole << std::endl;
    std::cout << "player 2 name: " << player2.name << " player 2 symbole : " << player2.symbole << std::endl;

};

