#include <ExampleStuff.hpp>
#include <iostream>
#include <vector>

enum class SquareType { penalty, start, reward };

struct Square {
public:
  Square(SquareType property) : property{property} {
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
  SquareType property;
  int moneyAmount;
};

struct Piece {
  int position{};
};

struct Board {
public:
  Board() {
    squares.push_back(Square{SquareType::start});
    for (int i = 1; i < 40; i++) {
      if (i % 2 == 0)
        squares.push_back(Square{SquareType::penalty});
      else
        squares.push_back(Square{SquareType::reward});
    }
  }
  std::vector<Square> squares;

private:
};

struct Player {
public:
  Player(std::string name) : name(name) {}

  std::string name;
  Piece piece;
  int money{1000};
};

class MonopolyGame {
public:
  MonopolyGame() { std::cout << "Hello in monopoly game!" << std::endl; };

  void addPlayer(std::string playerName) { players.push_back(playerName); }

  void makeTurn() {
    for (auto player : players) {
      std::cout << "Player " << player.name << "plays. Type dice value: ";
      int diceValue, diceValue2;
      std::cin >> diceValue >> diceValue2;
      // TO DO STH - update board
      int moveAmount = diceValue + diceValue2;
      updateBoard(player, moveAmount);
      printPlayerState(player);
    }
  }

private:
  std::vector<Player> players;
  Board board;
  void printPlayerState(const Player &player) {
    std::cout << "player: " << player.name << "\nmoney: " << player.money
              << "\nfield: " << player.piece.position << std::endl;
  }
  void updateBoard(Player &player, int moveAmount) {
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
};

int main() {
  MonopolyGame monopolygame;
  monopolygame.addPlayer("PlayerOne");
  // monopolygame.addPlayer("PlayerTwo");
  monopolygame.makeTurn();
  monopolygame.makeTurn();
}