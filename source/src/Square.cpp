#include "Square.hpp"
#include "Player.hpp"

void PrisonSquare::onStay(Player &player) { player.wantedLevel = 3; }
void PrisonSquare::onPass(Player &player) {}

BlackHoleSquare::BlackHoleSquare(std::unique_ptr<Square> square)
    : square(std::move(square)) {}
void BlackHoleSquare::onStay(Player &player) {
  if (isActivated) {
    square->onStay(player);
  }
  isActivated = (not isActivated);
}
void BlackHoleSquare::onPass(Player &player) {
  if (isActivated) {
    square->onPass(player);
  }
  isActivated = (not isActivated);
}

RandomSquare::RandomSquare() {
  squareOne = std::make_unique<PenaltySquare>();
  squareTwo = std::make_unique<EstateSquare>();
  squareThree = std::make_unique<DepositSquare>();
}
void RandomSquare::onStay(Player &player) {
  if (counter == 0) {
    squareOne->onStay(player);
    counter++;
  } else if (counter == 1) {
    squareTwo->onStay(player);
    counter++;
  } else {
    squareThree->onStay(player);
    counter = 0;
  }
}
void RandomSquare::onPass(Player &player) {
  if (counter == 0) {
    squareOne->onPass(player);
    counter++;
  } else if (counter == 1) {
    squareTwo->onPass(player);
    counter++;
  } else {
    squareThree->onPass(player);
    counter = 0;
  }
}

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
void EstateSquare::onStay(Player &player) {
  if (not owner) {
    if (player.wantsToBuy(value)) {
      player.money -= value;
      owner = &player;
    }
  } else if (player.name != owner->name) {
    player.money -= tax;
    owner->money += tax;
  }
}
void EstateSquare::onPass(Player &player) {}