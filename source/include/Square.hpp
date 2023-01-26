#pragma once

struct Square {
public:
  virtual ~Square() {}
  virtual int getMoneyChange() = 0;
  virtual int onPassMoneyChange() = 0;
};

struct PenaltySquare : public Square {
public:
  virtual int getMoneyChange();
  virtual int onPassMoneyChange();

private:
  int moneyAmount;
};

struct RewardSquare : public Square {
public:
  virtual int getMoneyChange();
  virtual int onPassMoneyChange();

private:
  int moneyAmount;
};

struct StartSquare : public Square {
public:
  virtual int getMoneyChange();
  virtual int onPassMoneyChange();

private:
  int moneyAmount;
};

struct DepositSquare : public Square {
public:
  virtual int getMoneyChange();
  virtual int onPassMoneyChange();

  int moneyDeposit{};
};