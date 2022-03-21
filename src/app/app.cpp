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
  isOnGame = false;
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
  if (InitSurfaces() == false) {
    return false;
  }
  Reset();

  return true;
}

void App::OnLoop() {}

void App::OnCleanUp() {
  SDL_FreeSurface(grid_image);
  SDL_FreeSurface(x_image);
  SDL_FreeSurface(o_image);
  SDL_FreeSurface(display);
  SDL_Quit();
}

}  // namespace game
