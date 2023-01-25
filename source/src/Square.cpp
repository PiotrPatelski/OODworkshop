#include "Square.hpp"

int PenaltySquare::getMoneyChange() { return -100; }

int RewardSquare::getMoneyChange() { return 100; }

int StartSquare::getMoneyChange() { return 0; }