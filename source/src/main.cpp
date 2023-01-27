#include "MonopolyGame.hpp"
#include <iostream>
#include <vector>

int main() {
  MonopolyGame monopolygame;
  monopolygame.addHumanPlayer("PlayerOne");
  monopolygame.addComputerPlayer("BOT Vladimir");
  monopolygame.play(10);
}