#pragma once
#include <vector>
#include <memory>
#include "Square.hpp"

struct Board {
public:
  Board() {
    squares.push_back(std::make_unique<StartSquare>());
    for (int i = 1; i < 40; i++) {
      if (i % 2 == 0)
        squares.push_back(std::make_unique<PenaltySquare>());
      else
        squares.push_back(std::make_unique<RewardSquare>());
    }
  }
  std::vector<std::unique_ptr<Square>> squares;

private:
};