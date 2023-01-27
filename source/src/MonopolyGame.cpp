#include <MonopolyGame.hpp>
#include <iostream>

void MonopolyGame::addHumanPlayer(std::string playerName) {
  players.push_back(
      std::make_unique<HumanPlayer>(playerName, board.getIterator()));
}

void MonopolyGame::addComputerPlayer(std::string playerName) {
  players.push_back(
      std::make_unique<ComputerPlayer>(playerName, board.getIterator()));
}

void MonopolyGame::play(int rounds) {
  for (int currentRound = 0; currentRound <= rounds; currentRound++) {
    makeTurn();
  }
}

void MonopolyGame::makeTurn() {
  for (auto &player : players) {
    printer.printWhoseTurn(player->name);
    player->move();
    printer.printPlayerState(*player);
  }
}
