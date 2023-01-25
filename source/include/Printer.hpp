#pragma once
#include "Player.hpp"
class Printer {
public:
  void printPlayerState(const Player &player) {
    std::cout << "player: " << player.name << "\nmoney: " << player.money
              << "\nfield: " << player.position << std::endl;
  }

  void printWhoseTurn(const std::string &playerName) {
    std::cout << "Player " << playerName << "plays.";
  }
};