#pragma once
#include "Square.hpp"
#include <iostream>
#include <memory>
#include <vector>

class BoardIterator {
public:
  BoardIterator(std::vector<std::shared_ptr<Square>> &squares)
      : squares(squares) {}

  void advance(Player &player, int diceValue) {
    for (int step = 0; step < diceValue; step++) {
      advanceByOne(player);
    }
    squares[currentPos]->onStay(player);
  }

  void advanceByOne(Player &player) {
    if (not isFirstMove) {
      squares[currentPos]->onPass(player);
    }

    if (currentPos == squares.size() - 1) {
      currentPos = 0;
    } else {
      currentPos++;
    }
    isFirstMove = false;
  }

  int getCurrentPos() const { return currentPos; }

private:
  std::vector<std::shared_ptr<Square>> &squares;
  int currentPos = 0;
  bool isFirstMove = true;
};

struct Board {
public:
  Board() {
    // 0 - StartSquare
    squares.push_back(std::make_shared<StartSquare>());
    // 1 - RealEstateSquare
    squares.push_back(std::make_shared<EstateSquare>());
    // 2 - RandomSquareEstateSquare (Penalty->Estate->Deposit)
    squares.push_back(std::make_shared<RandomSquare>());
    // 3 - BlackHole
    squares.push_back(
        std::make_shared<BlackHoleSquare>(std::make_unique<PenaltySquare>()));
    // 4 - Prison
    squares.push_back(std::make_shared<PrisonSquare>());
    // 5-9 - RewardSquare
    for (int i = 5; i < 10; i++) {
      squares.push_back(std::make_shared<RewardSquare>());
    }
    // 10 - RewardSquare
    squares.push_back(std::make_shared<RewardSquare>());

    // 11 - 40 - PenaltySquare
    for (int i = 11; i < 40; i++) {
      squares.push_back(std::make_shared<PenaltySquare>());
    }
  }
  BoardIterator getIterator() { return BoardIterator(squares); }

private:
  std::vector<std::shared_ptr<Square>> squares;
};
