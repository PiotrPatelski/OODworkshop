#include "Square.hpp"
#include "Player.hpp"

void PenaltySquare::onStay(Player &player) { player.money -= 100; }
void PenaltySquare::onPass(Player &player) {}

void RewardSquare::onStay(Player &player) { player.money += 100; }
void RewardSquare::onPass(Player &player) {}

void StartSquare::onStay(Player &player) {}
void StartSquare::onPass(Player &player) { player.money += 500; }

void DepositSquare::onStay(Player &player) {
  player.money += moneyDeposit;
  moneyDeposit = 0;
}
void DepositSquare::onPass(Player &player) {
  int stolenMoney = 50;
  player.money -= stolenMoney;
  moneyDeposit += stolenMoney;
}