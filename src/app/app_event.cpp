#include <SDL.h>

#include "app.h"

namespace game {

void App::OnEvent(SDL_Event* event) { Event::OnEvent(event); }

void App::OnLButtonDown(int mX, int mY) {
  int id = (mX / 200) + (mY / 200) * 3;
  if (grid[id] != GRID_TYPE_NONE) {
    return;
  }
  if (current_player == 0) {
    SetCell(id, GRID_TYPE_X);
  } else {
    SetCell(id, GRID_TYPE_O);
  }
  current_player = (current_player + 1) % 2;
}

void App::OnExit() { isRunning = false; }

}  // namespace  game
