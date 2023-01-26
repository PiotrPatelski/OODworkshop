#include "Square.hpp"

int PenaltySquare::getMoneyChange() { return -100; }
int PenaltySquare::onPassMoneyChange() { return 0; }

int RewardSquare::getMoneyChange() { return 100; }
int RewardSquare::onPassMoneyChange() { return 0; }

int StartSquare::getMoneyChange() { return 0; }
int StartSquare::onPassMoneyChange() { return 500; }

int DepositSquare::getMoneyChange() { return moneyDeposit; }
int DepositSquare::onPassMoneyChange() {
  const int stolenMoney = 50;
  moneyDeposit += stolenMoney;
  return -stolenMoney;
}