#include "app.h"

#include <SDL.h>

#include "surface.h"

using namespace renderer;

namespace game {

App::App() {
  grid_image = NULL;
  x_image = NULL;
  o_image = NULL;

  display = NULL;
  isRunning = true;
  current_player = 0;
}

App::~App() {}

int App::OnExcute() {
  if (OnInit() == false) {
    return -1;
  }

  SDL_Event event;
  while (isRunning) {
    while (SDL_PollEvent(&event)) {
      OnEvent(&event);
    }
    OnLoop();
    OnRender();
  }
  OnCleanUp();
  return 0;
}

bool App::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  if ((display = SDL_SetVideoMode(600, 600, 32,
                                  SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
    return false;
  }
  if ((grid_image = Surface::OnLoad("../assets/grid.bmp")) == NULL) {
    return false;
  }
  if ((x_image = Surface::OnLoad("../assets/x.bmp")) == NULL) {
    return false;
  }
  if ((o_image = Surface::OnLoad("../assets/o.bmp")) == NULL) {
    return false;
  }
  Surface::Transparent(x_image, 255, 255, 255);
  Surface::Transparent(o_image, 255, 255, 255);

  Reset();

  return true;
}

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

void App::OnLoop() {}

void App::OnRender() {
  Surface::OnDraw(display, grid_image, 0, 0);
  for (int i = 0; i < 9; i++) {
    int x = (i % 3) * 200;
    int y = (i / 3) * 200;
    if (grid[i] == GRID_TYPE_X) {
      Surface::OnDraw(display, x_image, x, y);
    } else if (grid[i] == GRID_TYPE_O) {
      Surface::OnDraw(display, o_image, x, y);
    }
  }
  SDL_Flip(display);
}

void App::OnCleanUp() {
  SDL_FreeSurface(grid_image);
  SDL_FreeSurface(x_image);
  SDL_FreeSurface(o_image);
  SDL_FreeSurface(display);
  SDL_Quit();
}

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
