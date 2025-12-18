#include "Board.hpp"
#include "Player/Player.hpp"

#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void draw_game_board(std::array<std::string, 9> const& board) {
   for(size_t i {0}; i < board.size(); i++ ) {
        std::string symbole = board[i];
        if(i % 3 == 0) {    
            std::cout << "| " << symbole << " | ";
        } else if (i % 3 == 1) {
            std::cout << symbole << " | " ;
        } else {
            std::cout << symbole << " |" << std::endl;
        }
    }
}

void check_valid_cell(std::array<std::string, 9>& board, Player const& player_playing) {
    std::array<int, 9> const cell_numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int player_playing_selected_cell {};

    bool valid_cell_number {false};
    
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
                board[player_playing_selected_cell - 1] = player_playing.symbole;
                valid_cell_number = true;
            } else {
                std::cout << "Veuillez choisir une case vide !\n" << std::endl;
            }
        }
    }while(!valid_cell_number);
}

void ia_choosing_cell(std::array<std::string, 9>& board, Player const& player_1,  Player const& player_2){
    std::vector<int> empty_board_cells {};

    //Détection des cases vides
    for(size_t i {0}; i < board.size(); i++) {
        int const position = static_cast<int>(i);
        if(board[position] != "X" && board[position] != "O") {
            empty_board_cells.push_back(static_cast<int>(i));
        }
    }

    //Détection des victoires
    for(size_t i {0}; i < empty_board_cells.size(); i++) {
        std::array<std::string, 9> testing_board {board};
        testing_board[empty_board_cells[i]] = player_2.symbole;

        if(check_victory(testing_board, player_2)) {
            board[empty_board_cells[i]] = player_2.symbole;
            return;
        } else {
            testing_board[empty_board_cells[i]] = player_1.symbole;

            if(check_victory(testing_board, player_1)) {
                board[empty_board_cells[i]] = player_2.symbole;
                return;
            }
        }
    }
    
    //Choix d'une case au hasard 
    std::srand(std::time(nullptr));
    int const chosen_cell = std::rand() % empty_board_cells.size();
    board[chosen_cell] = player_2.symbole;
}

bool check_victory(std::array<std::string, 9> const& board, Player const& player_playing) {
    for(int i {0}; i < 9; i+=3){
        if(board[i] == player_playing.symbole && board[i + 1] == player_playing.symbole && board[i + 2] == player_playing.symbole) {
            return true;
        }
    }

    for(int i {0}; i < 3; i++){
        if(board[i] == player_playing.symbole && board[i + 3] == player_playing.symbole && board[i + 6] == player_playing.symbole) {
            return true;
        }
    }

    if(board[0] == player_playing.symbole && board[4] == player_playing.symbole && board[8] == player_playing.symbole) {
        return true;
    }

    if(board[6] == player_playing.symbole && board[4] == player_playing.symbole && board[2] == player_playing.symbole) {
        return true;
    }

    return false;
};