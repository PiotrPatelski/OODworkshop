#include "Square.hpp"

// Square::Square(SquareType property) 
// : property{property} 
// {
//     switch (property) {
//     case SquareType::penalty:
//       moneyAmount = -100;
//       break;
//     case SquareType::reward:
//       moneyAmount = 100;
//       break;
//     case SquareType::start:
//       moneyAmount = 500;
//       break;
//     }
// }

int PenaltySquare::getMoneyPolicy()
{
    return -100;
}

int RewardSquare::getMoneyPolicy()
{
    return 100;
}

int StartSquare::getMoneyPolicy()
{
    return 500;
}