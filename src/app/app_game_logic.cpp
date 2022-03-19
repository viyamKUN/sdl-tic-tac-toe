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

void App::OnAutoTurn() {
  // Coumputer Turn
  // 남은 칸 중에서 적절한 칸에 토큰 놓기
  current_player = 0;
}

}  // namespace game
