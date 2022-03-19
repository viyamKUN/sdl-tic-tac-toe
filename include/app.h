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

 private:
  const char* AssetPath = "../assets/";
  const int GridSize = 200;
  const int GridCount = 3;

 public:
  App();
  ~App();

  int OnExcute();

 private:
  bool OnInit();
  void OnLoop();
  void OnCleanUp();

 private:
  void OnRender();
  bool InitSurfaces();

 private:
  void OnEvent(SDL_Event* event);
  void OnLButtonDown(int mX, int mY);
  void OnExit();

 private:
  void Reset();
  void SetCell(int id, int type);
  void OnAutoTurn();

 private:
  const char* GetFileDir(const char* fileName);
};

}  // namespace game

#endif
