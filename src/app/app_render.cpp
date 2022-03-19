#include <SDL.h>

#include "app.h"
#include "surface.h"

using namespace renderer;

namespace game {

bool App::InitSurfaces() {
  auto width = GridSize * GridCount;
  if ((display = SDL_SetVideoMode(width, width, 32,
                                  SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
    return false;
  }
  if ((grid_image = Surface::OnLoad(GetFileDir("grid.bmp"))) == NULL) {
    return false;
  }
  if ((x_image = Surface::OnLoad(GetFileDir("x.bmp"))) == NULL) {
    return false;
  }
  if ((o_image = Surface::OnLoad(GetFileDir("o.bmp"))) == NULL) {
    return false;
  }
  Surface::Transparent(x_image, 255, 255, 255);
  Surface::Transparent(o_image, 255, 255, 255);

  return true;
}

void App::OnRender() {
  Surface::OnDraw(display, grid_image, 0, 0);

  int whole_grid_count = GridCount * GridCount;
  for (int i = 0; i < whole_grid_count; i++) {
    int x = (i % GridCount) * GridSize;
    int y = (i / GridCount) * GridSize;
    if (grid[i] == GRID_TYPE_X) {
      Surface::OnDraw(display, x_image, x, y);
    } else if (grid[i] == GRID_TYPE_O) {
      Surface::OnDraw(display, o_image, x, y);
    }
  }
  SDL_Flip(display);
}

const char* App::GetFileDir(const char* fileName) {
  char* path = new char[strlen(AssetPath) + strlen(fileName)];
  strcat(path, AssetPath);
  strcat(path, fileName);
  return path;
}

}  // namespace game
