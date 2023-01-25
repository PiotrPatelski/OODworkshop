#include <ExampleStuff.hpp>
#include <iostream>
#include <vector>

enum class Square{
    penalty,
    start,
    reward
};

struct Board{
public:
    Board(){
        squares.push_back(Square::start);
        for(int i = 1; i < 40; i++)
        {
            if(i % 2 == 0)
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
  Board board;
};

int main() {
  MonopolyGame monopolygame;
  monopolygame.addPlayer("PlayerOne");
  monopolygame.addPlayer("PlayerTwo");
}