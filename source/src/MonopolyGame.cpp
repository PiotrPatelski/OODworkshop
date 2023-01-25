#include <MonopolyGame.hpp>
#include <iostream>

void MonopolyGame::addPlayer(std::string playerName) {
  players.push_back(Player(playerName, board.getIterator()));
}

void MonopolyGame::play(int rounds) {
  for (int currentRound = 0; currentRound <= rounds; currentRound++) {
    makeTurn();
  }
}

void MonopolyGame::makeTurn() {
  for (auto &player : players) {
    printer.printWhoseTurn(player.name);
    // updateBoard(player);
    player.move();
    printer.printPlayerState(player);
  }
}

