#pragma once
#include <vector>
#include "Square.hpp"

struct Board {
public:
  Board() {
    squares.push_back(Square{SquareType::start});
    for (int i = 1; i < 40; i++) {
      if (i % 2 == 0)
        squares.push_back(Square{SquareType::penalty});
      else
        squares.push_back(Square{SquareType::reward});
    }
  }
  std::vector<Square> squares;

private:
};