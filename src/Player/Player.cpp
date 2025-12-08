#include "Player.hpp"

#include <iostream>
#include <string>

Player create_player() {
    std::string player_name {};
    char player_symbole {};

    std::cout << "Quel est votre nom ? :" << std::endl;
    std::cin >> player_name;

    do {
        std::cout << "Quel symbole vous souhaitez être ? (X/O) :" << std::endl;
        std::cin >> player_symbole;
    }
    while(player_symbole != 'X' || player_symbole != 'O');

    Player created_player = {player_name, player_symbole};

    return created_player;
}