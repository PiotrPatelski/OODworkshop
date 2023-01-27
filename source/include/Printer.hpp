#pragma once
#include "Player.hpp"
class Printer {
public:
  void printPlayerState(const Player &player) {
    std::cout << "player: " << player.name << " money: " << player.money
              << " field: " << player.position.getCurrentPos() << std::endl
              << std::endl;
  }

  void printWhoseTurn(const std::string &playerName) {
    std::cout << "Player " << playerName << "plays." << std::endl;
  }
};