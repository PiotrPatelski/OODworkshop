#pragma once
#include <iostream>

struct Dice {
  virtual int getRollSum() = 0;
  virtual ~Dice() {}
};

struct UserControlledDice : public Dice {
  virtual int getRollSum() override {
    int diceValue, diceValue2;
    std::cout << "Enter 1st dice value: " << std::endl;
    std::cin >> diceValue;
    std::cout << "Enter 2nd dice value: " << std::endl;
    std::cin >> diceValue2;
    return diceValue + diceValue2;
  }
};

struct ComputerControlledDice : public Dice {
  virtual int getRollSum() override { return 5; }
};