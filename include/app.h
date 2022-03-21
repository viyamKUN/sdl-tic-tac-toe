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
  enum GRID_TYPE { NONE = 0, PLAYER, COMPUTER };

 private:
  const char* AssetPath = "../assets/";
  const int GridSize = 200;
  const int GridCount = 3;
  const int WholeGridCount = 9;

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
  void CheckWinner();
  void EndGame(int winner);

 private:
  const char* GetFileDir(const char* fileName);
};

}  // namespace game

#endif
