#pragma once

struct Square {
public:
  virtual ~Square() {}
  virtual int getMoneyChange() = 0;
};

struct PenaltySquare : public Square {
public:
  virtual int getMoneyChange();

private:
  int moneyAmount;
};

struct RewardSquare : public Square {
public:
  virtual int getMoneyChange();

private:
  int moneyAmount;
};

struct StartSquare : public Square {
public:
  virtual int getMoneyChange();

private:
  int moneyAmount;
};