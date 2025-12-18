#pragma once

#include <string>

struct Player {
    std::string name {};
    std::string symbole {};
};

std::pair<Player, Player> create_player(bool with_ai);