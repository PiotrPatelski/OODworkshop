#include <ExampleStuff.hpp>
#include <iostream>
#include <vector>

struct Player {
public:
  Player(std::string name) : name(name) {}

private:
  std::string name;
  int money{};
};

class MonopolyGame {
public:
  MonopolyGame() { std::cout << "Hello in monopoly game!" << std::endl; };

  void addPlayer(std::string playerName) { players.push_back(playerName); }

private:
  std::vector<Player> players;
};

int main() {
  MonopolyGame monopolygame;
  monopolygame.addPlayer("PlayerOne");
  monopolygame.addPlayer("PlayerTwo");
}