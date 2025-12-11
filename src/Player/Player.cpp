#include "Player.hpp"

#include <iostream>
#include <string>
#include <optional>

std::pair<Player, Player> create_player() {
    std::string player_1_name {};
    char player_1_symbole {};

    std::cout << "Quel est le nom du joueur 1 ? :" << std::endl;
    std::cin >> player_1_name;

    do {
        std::cout << "Quel symbole souhaitez-vous être ? (X/O) :" << std::endl;
        std::cin >> player_1_symbole;
    }
    while(player_1_symbole != 'X' && player_1_symbole != 'O');

    std::string player_2_name {};
    char player_2_symbole {player_1_symbole == 'X' ? 'O' : 'X'};

    std::cout << "Quel est le nom du joueur 2 ? :" << std::endl;
    std::cin >> player_2_name;


    Player player_1 = {player_1_name, player_1_symbole};
    Player player_2 = {player_2_name, player_2_symbole};

    return std::make_pair(player_1, player_2);
}