#pragma once
#include <iostream>

struct Player {
public:
  Player(std::string name) : name(name) {}
  void updateMoneyBalance(const int moneyChange) { money += moneyChange; }

  std::string name;
  int position;
  int money{1000};
};