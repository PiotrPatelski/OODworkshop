#pragma once
#include <iostream>
#include "Piece.hpp"

struct Player {
public:
  Player(std::string name) : name(name) {}

  std::string name;
  Piece piece;
  int money{1000};
};