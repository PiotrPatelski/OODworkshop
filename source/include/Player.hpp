#pragma once
#include "Board.hpp"
#include "Dice.hpp"
#include <iostream>

struct Player {
public:
  Player(const std::string &name, BoardIterator position)
      : name(name), position(position) {}
  virtual void move() = 0;
  virtual bool wantsToBuy() = 0;
  virtual ~Player() {}

  std::string name;
  BoardIterator position;
  int money{1000};
  std::shared_ptr<Dice> dice;
};

struct HumanPlayer : public Player {
public:
  HumanPlayer(const std::string &name, BoardIterator position)
      : Player(name, position) {
    dice = std::make_shared<UserControlledDice>();
  }

  virtual void move() override { position.advance(*this, dice->getRollSum()); }
  virtual bool wantsToBuy() override {
    bool definetly;
    std::cin >> definetly;
    return definetly;
  }
};

struct ComputerPlayer : public Player {
public:
  ComputerPlayer(const std::string &name, BoardIterator position)
      : Player(name, position) {
    dice = std::make_shared<ComputerControlledDice>();
  }

  virtual void move() override { position.advance(*this, dice->getRollSum()); }
  virtual bool wantsToBuy() override {return true;}
};