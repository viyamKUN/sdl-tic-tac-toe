#include <SDL.h>

#include <iostream>

#include "app.h"

namespace game {

void App::Reset() {
  for (int i = 0; i < WholeGridCount; i++) {
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
  for (int i = 0; i < WholeGridCount; i++) {
    if (grid[i] == GRID_TYPE_NONE) {
      SetCell(i, GRID_TYPE_O);
      break;
    }
  }
  current_player = 0;
}

// Check winner
void App::CheckWinner() {
  bool slope_down = true;
  bool slope_up = true;
  int center_index = (GridCount - 1) / 2;
  int center = grid[center_index * (GridCount + 1)];

  for (int i = 0; i < GridCount; i++) {
    int row_first = grid[i * GridCount];
    int column_first = grid[i];
    bool row = true;
    bool column = true;
    for (int j = 0; j < GridCount; j++) {
      // row check
      if (row_first != grid[i * GridCount + j]) row = false;
      // column check
      if (column_first != grid[j * GridCount + i]) column = false;
    }
    // slope check
    if (center != grid[i * GridCount + i]) slope_down = false;
    if (center != grid[(i + 1) * (GridCount - 1)]) slope_up = false;

    if (row_first != GRID_TYPE_NONE)
      if (row) EndGame(row_first);
    if (column_first != GRID_TYPE_NONE)
      if (column) EndGame(column_first);
  }
  if (center != GRID_TYPE_NONE)
    if (slope_down || slope_up) EndGame(center);
}

// Show winner and quit game
void App::EndGame(int winner) {
  const char* winner_name = (winner == 1 ? "player" : "computer");
  std::cout << "winner is " << winner_name << std::endl;
}

}  // namespace game
