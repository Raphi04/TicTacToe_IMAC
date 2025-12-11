#pragma once

#include <string>

struct Player {
    std::string name {};
    char symbole {};
};

std::pair<Player, Player> create_player();