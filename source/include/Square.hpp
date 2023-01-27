#pragma once
#include <memory>

struct Player;

struct Square {
public:
  virtual ~Square() {}
  virtual void onStay(Player &player) = 0;
  virtual void onPass(Player &player) = 0;
};

struct PrisonSquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);
};

struct BlackHoleSquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);
  BlackHoleSquare(std::unique_ptr<Square> square);

private:
  bool isActivated = true;
  std::unique_ptr<Square> square;
};

struct RandomSquare : Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);
  RandomSquare();

private:
  std::unique_ptr<Square> squareOne;
  std::unique_ptr<Square> squareTwo;
  std::unique_ptr<Square> squareThree;
  int counter = 0;
};

struct PenaltySquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);

private:
  int moneyAmount;
};

struct RewardSquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);

private:
  int moneyAmount;
};

struct StartSquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);

private:
  int moneyAmount;
};

struct DepositSquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);

  int moneyDeposit{};
};

struct EstateSquare : public Square {
public:
  virtual void onStay(Player &player);
  virtual void onPass(Player &player);

  Player *owner;
  int value{1500};
  int tax{75};
};