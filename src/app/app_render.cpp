#include <SDL.h>

#include "app.h"
#include "surface.h"

using namespace renderer;

namespace game {

bool App::InitSurfaces() {
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

  return true;
}

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

}  // namespace game
