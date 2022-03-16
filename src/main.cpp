#include <iostream>

#include "app.h"

int main(int argc, char **argv) {
  std::cout << "run Tic Tac Toe" << std::endl;
  Game::App game_app;
  return game_app.OnExcute();
}
