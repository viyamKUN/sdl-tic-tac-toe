#include <SDL.h>

#include "app.h"

namespace game {

void App::OnEvent(SDL_Event* event) { Event::OnEvent(event); }

void App::OnLButtonDown(int mX, int mY) {
  int id = (mX / GridSize) + (mY / GridSize) * 3;
  if (grid[id] != NONE) {
    return;
  }
  if (current_player == 0) {
    SetCell(id, PLAYER);
    current_player = 1;
    OnAutoTurn();
  }
  CheckWinner();
}

void App::OnExit() { isRunning = false; }

}  // namespace  game
