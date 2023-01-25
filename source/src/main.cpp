#include <iostream>
#include <vector>
#include "MonopolyGame.hpp"

int main() {
  MonopolyGame monopolygame;
  monopolygame.addPlayer("PlayerOne");
  // monopolygame.addPlayer("PlayerTwo");
  monopolygame.makeTurn();
  monopolygame.makeTurn();
}