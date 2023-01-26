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
    onPassedSum = 0;
    for (auto localPos = 0; localPos < moveAmount; localPos++) {
      if (currentPos == squares.size() - 1) {
        currentPos = 0;
      } else {
        currentPos++;
      }
      int previousPos = (currentPos == 0) ? squares.size() - 1 : currentPos - 1;
      onPassedSum += squares[previousPos]->onPassMoneyChange();
    }
  }

  int getCurrentPos() const { return currentPos; }
  int getSquareChange() {
    return (squares[currentPos]->getMoneyChange() + onPassedSum);
  }

private:
  std::vector<std::unique_ptr<Square>> &squares;
  int currentPos = 0;
  bool crossedStart = false;
  int onPassedSum = 0;
};

struct Board {
public:
  Board() {
    // 0 - StartSquare
    squares.push_back(std::make_unique<StartSquare>());
    // 1-9 - RewardSquare
    for (int i = 1; i < 10; i++) {
      squares.push_back(std::make_unique<RewardSquare>());
    }
    // 10 - DepositSquare
    squares.push_back(std::make_unique<DepositSquare>());

    for (int i = 11; i < 40; i++) {
      squares.push_back(std::make_unique<PenaltySquare>());
    }
  }
  BoardIterator getIterator() { return BoardIterator(squares); }

private:
  std::vector<std::unique_ptr<Square>> squares;
};
