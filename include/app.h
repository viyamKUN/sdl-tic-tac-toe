#ifndef _ADD_H_
#define _ADD_H_

#include <SDL.h>

#include "event.h"

namespace game {

class App : Event {
 private:
  bool isRunning;
  SDL_Surface* display;

  SDL_Surface* grid_image;
  SDL_Surface* x_image;
  SDL_Surface* o_image;
  int current_player;

 private:
  int grid[9];
  enum { GRID_TYPE_NONE = 0, GRID_TYPE_X, GRID_TYPE_O };

 public:
  App(/* args */);
  ~App();

  int OnExcute();
  bool OnInit();
  void OnLoop();
  void OnRender();
  void OnCleanUp();

 public:
  void OnEvent(SDL_Event* event);
  void OnLButtonDown(int mX, int mY);
  void OnExit();

 public:
  void Reset();
  void SetCell(int id, int type);
};
}  // namespace game

#endif
