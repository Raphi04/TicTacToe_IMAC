#include "./Gamemode.hpp"
#include "../Player/Player.hpp"

#include<iostream>

void player_vs_player() {
    std::pair<Player, Player> const players = create_player();
    
    Player const& player1 = players.first;
    Player const& player2 = players.second;

    std::cout << "player 1 name: " << player1.name << " player 1 symbole : " << player1.symbole << std::endl;
    std::cout << "player 2 name: " << player2.name << " player 2 symbole : " << player2.symbole << std::endl;

};

void player_vs_ia() {

};

