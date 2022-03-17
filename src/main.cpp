#include <iostream>

#include "app.h"

int main(int argc, char **argv) {
  std::cout << "run Tic Tac Toe" << std::endl;
  game::App game_app;
  return game_app.OnExcute();
}
