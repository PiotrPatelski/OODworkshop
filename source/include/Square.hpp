#pragma once

struct Square {
public:
  virtual ~Square(){}
  virtual int getMoneyPolicy() = 0;
};

struct PenaltySquare : public Square{
public:
  virtual int getMoneyPolicy();
private:
  int moneyAmount;
};

struct RewardSquare : public Square{
public:
  virtual int getMoneyPolicy();
private:
  int moneyAmount;
};

struct StartSquare : public Square{
public:
  virtual int getMoneyPolicy();
private:
  int moneyAmount;
};