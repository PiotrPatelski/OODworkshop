#pragma once

enum class SquareType { penalty, start, reward };

struct Square {
public:
  Square(SquareType);
  SquareType property;
  int moneyAmount;
};