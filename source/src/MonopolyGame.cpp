#include <MonopolyGame.hpp>
#include <iostream>

void MonopolyGame::addPlayer(std::string playerName) {
  players.push_back(playerName);
}

void MonopolyGame::play(int rounds) {
  for (int currentRound = 0; currentRound <= rounds; currentRound++) {
    makeTurn();
  }
}

void MonopolyGame::makeTurn() {
  for (auto &player : players) {
    printer.printWhoseTurn(player.name);
    updateBoard(player, Dice{}.getRollSum());
    printer.printPlayerState(player);
  }
}

void MonopolyGame::updateBoard(Player &player, int moveAmount) {
  if ((player.position + moveAmount) < board.squares.size()) {
    player.position += moveAmount;
  } else {
    player.position = moveAmount - (board.squares.size() - player.position);
    if (not player.position == 0) {
      player.money += 500;
    }
  }

  player.updateMoneyBalance(board.squares[player.position]->getMoneyChange());
}
