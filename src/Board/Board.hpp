#pragma once

#include <Player/Player.hpp>

#include <array>
#include <string>

void draw_game_board(std::array<std::string, 9> const&);

void check_valid_cell(std::array<std::string, 9>& board, Player const& player_playing);

void ai_choosing_cell(std::array<std::string, 9>& board, Player const& player_1,  Player const& player_2);

bool check_victory(std::array<std::string, 9> const& board, Player const& player_playing);