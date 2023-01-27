#pragma once
#include "Board.hpp"
#include "Dice.hpp"
#include <iostream>

struct Player {
public:
  Player(const std::string &name, BoardIterator position)
      : name(name), position(position) {}
  virtual void move() = 0;
  virtual bool wantsToBuy(int price) = 0;
  virtual ~Player() {}

  std::string name;
  BoardIterator position;
  int money{1000};
  std::shared_ptr<Dice> dice;
  int wantedLevel{0};
};

struct HumanPlayer : public Player {
public:
  HumanPlayer(const std::string &name, BoardIterator position)
      : Player(name, position) {
    dice = std::make_shared<UserControlledDice>();
  }

  virtual void move() override {
    if (wantedLevel == 0) {
      position.advance(*this, dice->getRollSum());
    } else {
      wantedLevel--;
    }
  }
  virtual bool wantsToBuy(int price) override {
    bool definetly;
    std::cout << "Type 1 if you want to buy\n";
    std::cin >> definetly;
    bool decision{false};
    if (money >= price) {
      decision = true;
    } else {
      std::cout << "You dont have enough money\n";
    }
    return decision;
  }
};

struct ComputerPlayer : public Player {
public:
  ComputerPlayer(const std::string &name, BoardIterator position)
      : Player(name, position) {
    dice = std::make_shared<ComputerControlledDice>();
  }

  virtual void move() override { position.advance(*this, dice->getRollSum()); }
  virtual bool wantsToBuy(int price) override { return (money >= price); }
};