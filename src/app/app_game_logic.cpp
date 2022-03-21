#include <SDL.h>

#include <iostream>

#include "app.h"

namespace game {

void App::Reset() {
  for (int i = 0; i < WholeGridCount; i++) {
    grid[i] = NONE;
  }
  isOnGame = true;
}

void App::SetCell(int id, int type) {
  if (id < 0 || id >= 9) return;
  if (type < 0 || type > COMPUTER) return;
  grid[id] = type;
}

// Coumputer Turn
void App::OnAutoTurn() {
  int selected_Index = 0;
  int center = ((GridCount - 1) / 2) * (GridCount + 1);
  if (grid[center] == NONE) {
    // Select the center as the top priority
    selected_Index = center;
  } else {
    // Defend if there are (GridCount - 1) in a line
    int index = GetGridIndexToDefendOrAttack(COMPUTER);
    if (index < 0) {
      selected_Index = GetEmptyGridIndexRandom();
    } else {
      selected_Index = index;
    }
  }
  SetCell(selected_Index, COMPUTER);
  current_player = 0;
  CheckWinner();
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

    if (row_first != NONE)
      if (row) EndGame(row_first);
    if (column_first != NONE)
      if (column) EndGame(column_first);
  }
  if (center != NONE)
    if (slope_down || slope_up) EndGame(center);
}

// Show winner and quit game
void App::EndGame(int winner) {
  const char* winner_name = (winner == PLAYER ? "player" : "computer");
  std::cout << "winner is " << winner_name << std::endl;
  isOnGame = false;
}

int App::GetGridIndexToDefendOrAttack(int turn) { return -1; }

int App::GetEmptyGridIndexRandom() {
  int start_index = rand() % WholeGridCount;
  int index = start_index;
  while (index != start_index - 1) {
    if (grid[index] == NONE) {
      return index;
    }
    index++;
    if (index == WholeGridCount) index = 0;
  }
  return 0;
}

}  // namespace game
