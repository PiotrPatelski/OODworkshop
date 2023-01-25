#include "MonopolyGame.hpp"
#include <iostream>
#include <vector>

int main() {
  MonopolyGame monopolygame;
  monopolygame.addPlayer("PlayerOne");
  monopolygame.play(10);
}