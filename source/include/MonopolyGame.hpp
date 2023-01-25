#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "Dice.hpp"

class MonopolyGame {
public:
  MonopolyGame()
  { std::cout << "Hello in monopoly game!" << std::endl; };

  void addPlayer(std::string playerName);

  void makeTurn();

private:
  std::vector<Player> players;
  Board board;
  void printPlayerState(const Player &player);
  void updateBoard(Player &player, int moveAmount);
};