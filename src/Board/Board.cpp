#include "Board.hpp"

#include <array>
#include <iostream>

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