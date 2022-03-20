#include <SDL.h>

#include <iostream>

#include "app.h"

namespace game {

void App::Reset() {
  int whole_grid_count = GridCount * GridCount;
  for (int i = 0; i < whole_grid_count; i++) {
    grid[i] = GRID_TYPE_NONE;
  }
}

void App::SetCell(int id, int type) {
  if (id < 0 || id >= 9) return;
  if (type < 0 || type > GRID_TYPE_O) return;
  grid[id] = type;
}

// Coumputer Turn
void App::OnAutoTurn() {
  // 시작 시: 상대가 가운데에서 하면 모서리 방어, 아니면 반대
  // 두 개 연속으로 있는 곳이 있으면 방어
  int whole_grid_count = GridCount * GridCount;
  for (int i = 0; i < whole_grid_count; i++) {
    if (grid[i] == GRID_TYPE_NONE) {
      SetCell(i, GRID_TYPE_O);
      break;
    }
  }
  current_player = 0;
}

}  // namespace game
