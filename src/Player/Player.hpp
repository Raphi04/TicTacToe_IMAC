#pragma once

#include <string>

struct Player {
    std::string name {};
    std::string symbole {};
    bool is_ai {false};
};

std::pair<Player, Player> create_player(bool with_ai);