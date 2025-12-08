#pragma once

#include <string>

struct Player {
    std::string name {};
    char symbole {};
};

Player create_player();