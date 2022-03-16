#include "surface.h"

namespace Game {
Surface::Surface(/* args */) {}

Surface::~Surface() {}

SDL_Surface* Surface::OnLoad(const char* File) {
  SDL_Surface* loaded_surface = NULL;
  SDL_Surface* result_surface = NULL;

  if ((loaded_surface = SDL_LoadBMP(File)) == NULL) {
    return NULL;
  }
  result_surface = SDL_DisplayFormat(loaded_surface);
  SDL_FreeSurface(loaded_surface);
  return result_surface;
}

bool Surface::OnDraw(SDL_Surface* destination, SDL_Surface* src, int x, int y) {
  if (destination == NULL || src == NULL) {
    return false;
  }
  SDL_Rect destination_rect;
  destination_rect.x = x;
  destination_rect.y = y;
  SDL_BlitSurface(src, NULL, destination, &destination_rect);
  return true;
}

}  // namespace Game
