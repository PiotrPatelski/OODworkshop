#pragma once
#include "Board.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Printer.hpp"
#include <iostream>
#include <vector>

class MonopolyGame {
public:
  MonopolyGame() { std::cout << "Hello in monopoly game!" << std::endl; };

  void addHumanPlayer(std::string playerName);
  void addComputerPlayer(std::string playerName);
  void play(int rounds);

private:
  std::vector<std::unique_ptr<Player>> players;
  Board board;
  Printer printer;
  void printPlayerState(const Player &player);
  void updateBoard(Player &player, int moveAmount);
  void makeTurn();
};