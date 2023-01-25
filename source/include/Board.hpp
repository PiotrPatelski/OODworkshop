#pragma once
#include "Square.hpp"
#include <memory>
#include <vector>

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
  // getIterator(){

  //}
  // private
  std::vector<std::unique_ptr<Square>> squares;

private:
};

class BoardIterator {
public:
  void next() {
    // moveBy 1
  }

private:
  std::vector<std::unique_ptr<Square>> &squares;
  int currentPos;
};