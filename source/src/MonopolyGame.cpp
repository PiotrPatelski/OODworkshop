#include <MonopolyGame.hpp>
#include <iostream>

void MonopolyGame::addPlayer(std::string playerName)
{ 
    players.push_back(playerName); 
}

void MonopolyGame::makeTurn() 
{
    for (auto& player : players) 
    {
        std::cout << "Player " << player.name << "plays. Type dice value: ";
        updateBoard(player, Dice{}.getRollSum());
        printPlayerState(player);
    }
}

void MonopolyGame::printPlayerState(const Player &player) 
{
    std::cout << "player: " << player.name << "\nmoney: " << player.money
              << "\nfield: " << player.piece.position << std::endl;
}

void MonopolyGame::updateBoard(Player &player, int moveAmount) 
{
    if ((player.piece.position + moveAmount) < board.squares.size()) {
      player.piece.position += moveAmount;
    } else {
      player.piece.position =
          moveAmount - (board.squares.size() - player.piece.position);
      if (not player.piece.position == 0) {
        player.money += 500;
      }
    }

    player.money += board.squares[player.piece.position]->getMoneyPolicy();
  
}
