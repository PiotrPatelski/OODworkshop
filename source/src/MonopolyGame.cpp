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
        int diceValue, diceValue2;
        std::cin >> diceValue >> diceValue2;
        // TO DO STH - update board
        int moveAmount = diceValue + diceValue2;
        updateBoard(player, moveAmount);
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

    auto square = board.squares[player.piece.position];
    player.money += square.moneyAmount;
  
}
