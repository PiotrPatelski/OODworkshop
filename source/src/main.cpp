#include <ExampleStuff.hpp>
#include <iostream>
#include <vector>

enum class Square { penalty, start, reward };

struct Piece {
  int position{};
};

struct Board {
public:
  Board() {
    squares.push_back(Square::start);
    for (int i = 1; i < 40; i++) {
      if (i % 2 == 0)
        squares.push_back(Square::penalty);
      else
        squares.push_back(Square::reward);
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
  int money{};
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
      printPlayerState(player);
    }
  }

private:
  std::vector<Player> players;
  Board board;
  void printPlayerState(const Player &player) {}
};

int main() {
  MonopolyGame monopolygame;
  monopolygame.addPlayer("PlayerOne");
  monopolygame.addPlayer("PlayerTwo");
  monopolygame.makeTurn();
}