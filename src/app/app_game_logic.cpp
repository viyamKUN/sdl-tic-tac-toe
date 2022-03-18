#include <SDL.h>

#include "app.h"

namespace game {

void App::Reset() {
  for (int i = 0; i < 9; i++) {
    grid[i] = GRID_TYPE_NONE;
  }
}

void App::SetCell(int id, int type) {
  if (id < 0 || id >= 9) return;
  if (type < 0 || type > GRID_TYPE_O) return;
  grid[id] = type;
}

}  // namespace game
