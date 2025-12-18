#include "Player.hpp"

#include <iostream>
#include <string>
#include <optional>

std::pair<Player, Player> create_player(bool with_ai) {
    std::string player_1_name {};
    std::string player_1_symbole {};

    std::cout << "Quel est le nom du joueur 1 ? :" << std::endl;
    std::cin >> player_1_name;

    do {
        std::cout << "\nQuel symbole souhaitez-vous etre ? (X/O) :" << std::endl;
        std::cin >> player_1_symbole;

        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(255, '\n');
        };
    }
    while(player_1_symbole != "X" && player_1_symbole != "O");

    std::string player_2_name {};
    if(!with_ai) {

        std::cout << "\nQuel est le nom du joueur 2 ? :" << std::endl;
        std::cin >> player_2_name;
    } else {
        player_2_name = "IA";
    }

    std::string player_2_symbole {player_1_symbole == "X" ? "O" : "X"};

    Player player_1 = {player_1_name, player_1_symbole};
    Player player_2 = {player_2_name, player_2_symbole, true};

    return std::make_pair(player_1, player_2);
}