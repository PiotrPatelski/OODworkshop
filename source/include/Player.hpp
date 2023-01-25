#pragma once
#include <iostream>
#include "Board.hpp"

struct Player {
public:
  Player(const std::string& name, BoardIterator position) : name(name), position(position) {}
  void updateMoneyBalance() {
    money += position.getSquareChange(); 
}
  void move() {

    position.advance(Dice{}.getRollSum());
    updateMoneyBalance();
}

  std::string name;
  BoardIterator position;
  int money{1000};
};