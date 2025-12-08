#include "Board.hpp"
#include <vector>
#include <iostream>

void draw_game_board(std::vector<char> const& board) {
    for(size_t i {1}; i <= board.size(); i++ ) {
        char symbole = board[i] ? board[i] : '.';
        if(i % 3 == 1) {
            std::cout << "| " << symbole << " | ";
        } else if (i % 3 == 2) {
            std::cout << symbole << " | " ;
        } else {
            std::cout << symbole << " |" << std::endl;
        }
    }
}  