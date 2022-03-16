#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>

namespace Game {
class Surface {
 public:
  Surface(/* args */);
  ~Surface();
  static SDL_Surface* OnLoad(const char* File);
  static bool OnDraw(SDL_Surface* destination, SDL_Surface* src, int x, int y);
};
}  // namespace Game

#endif
