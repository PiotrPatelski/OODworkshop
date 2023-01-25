#pragma once
#include "Square.hpp"
#include <iostream>
#include <memory>
#include <vector>

class BoardIterator {
public:
  BoardIterator(std::vector<std::unique_ptr<Square>> &squares)
      : squares(squares) {}

  void advance(int moveAmount) {
    int result = (currentPos + moveAmount) % squares.size();
    if (result < currentPos)
      crossedStart = true;
    currentPos = result;
  }

  int getCurrentPos() const { return currentPos; }
  int getSquareChange() {
    int squareChange = squares[currentPos]->getMoneyChange();
    if (crossedStart)
      return squareChange + 500;
    else
      return squareChange;
  }

private:
  std::vector<std::unique_ptr<Square>> &squares;
  int currentPos = 0;
  bool crossedStart = false;
};

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
  BoardIterator getIterator() { return BoardIterator(squares); }

private:
  std::vector<std::unique_ptr<Square>> squares;

private:
};
