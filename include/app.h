#ifndef _ADD_H_
#define _ADD_H_

#include <SDL.h>

#include "event.h"

namespace Game {
class App : Event {
 private:
  bool isRunning;
  SDL_Surface* display;

  SDL_Surface* grid;
  SDL_Surface* x_image;
  SDL_Surface* o_image;

 public:
  App(/* args */);
  ~App();

  int OnExcute();
  bool OnInit();
  void OnEvent(SDL_Event* event);
  void OnExit();
  void OnLoop();
  void OnRender();
  void OnCleanUp();
};
}  // namespace Game

#endif
