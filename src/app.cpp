#include "app.h"

#include <SDL.h>

#include "surface.h"

namespace Game {
App::App() {
  grid = NULL;
  x_image = NULL;
  o_image = NULL;

  display = NULL;
  isRunning = true;
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
  if ((grid = Surface::OnLoad("../assets/grid.bmp")) == NULL) {
    return false;
  }
  if ((x_image = Surface::OnLoad("../assets/x.bmp")) == NULL) {
    return false;
  }
  if ((o_image = Surface::OnLoad("../assets/o.bmp")) == NULL) {
    return false;
  }
  return true;
}

void App::OnEvent(SDL_Event* event) { Event::OnEvent(event); }

void App::OnExit() { isRunning = false; }

void App::OnLoop() {}

void App::OnRender() {
  Surface::OnDraw(display, grid, 0, 0);
  SDL_Flip(display);
}

void App::OnCleanUp() {
  SDL_FreeSurface(grid);
  SDL_FreeSurface(x_image);
  SDL_FreeSurface(o_image);
  SDL_FreeSurface(display);
  SDL_Quit();
}

}  // namespace Game
