#pragma once
#include <memory>

struct Player;

struct Square {
public:
  virtual ~Square() {}
  virtual void onStay(Player& player) = 0;
  virtual void onPass(Player& player) = 0;
};

struct PenaltySquare : public Square {
public:
  virtual void onStay(Player& player);
  virtual void onPass(Player& player);

private:
  int moneyAmount;
};

struct RewardSquare : public Square {
public:
  virtual void onStay(Player& player);
  virtual void onPass(Player& player);

private:
  int moneyAmount;
};

struct StartSquare : public Square {
public:
  virtual void onStay(Player& player);
  virtual void onPass(Player& player);

private:
  int moneyAmount;
};

struct DepositSquare : public Square {
public:
  virtual void onStay(Player& player);
  virtual void onPass(Player& player);

  int moneyDeposit{};
};

struct EstateSquare : public Square {
public:
  virtual void onStay(Player& player);
  virtual void onPass(Player& player);

  bool isOwned{false};
  Player& owner;
  int value{500};
  int tax{75};
};