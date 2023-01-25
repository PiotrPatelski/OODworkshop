#include "Square.hpp"

Square::Square(SquareType property) 
: property{property} 
{
    switch (property) {
    case SquareType::penalty:
      moneyAmount = -100;
      break;
    case SquareType::reward:
      moneyAmount = 100;
      break;
    case SquareType::start:
      moneyAmount = 500;
      break;
    }
}