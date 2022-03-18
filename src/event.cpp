#include "event.h"

namespace game {

Event::Event(/* args */) {}
Event::~Event() {}

// Get events and call valid method
void Event::OnEvent(SDL_Event* event) {
  switch (event->type) {
    case SDL_ACTIVEEVENT: {
      switch (event->active.state) {
        case SDL_APPMOUSEFOCUS:
          if (event->active.gain)
            OnMouseFocus();
          else
            OnMouseBlur();
          break;
        case SDL_APPINPUTFOCUS: {
          if (event->active.gain)
            OnInputFocus();
          else
            OnInputBlur();
          break;
        }
        case SDL_APPACTIVE: {
          if (event->active.gain)
            OnRestore();
          else
            OnMinimize();
          break;
        }
      }
      break;
    }

    case SDL_KEYDOWN: {
      OnKeyDown(event->key.keysym.sym, event->key.keysym.mod,
                event->key.keysym.unicode);
    }

    case SDL_KEYUP: {
      OnKeyUp(event->key.keysym.sym, event->key.keysym.mod,
              event->key.keysym.unicode);
    }

    case SDL_MOUSEMOTION: {
      OnMouseMove(event->motion.x, event->motion.y, event->motion.xrel,
                  event->motion.yrel,
                  (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                  (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                  (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
    }

    case SDL_MOUSEBUTTONDOWN: {
      switch (event->button.button) {
        case SDL_BUTTON_LEFT: {
          OnLButtonDown(event->button.x, event->button.y);
          break;
        }
        case SDL_BUTTON_RIGHT: {
          OnRButtonDown(event->button.x, event->button.y);
          break;
        }
        case SDL_BUTTON_MIDDLE: {
          OnMButtonDown(event->button.x, event->button.y);
          break;
        }
      }
      break;
    }

    case SDL_MOUSEBUTTONUP: {
      switch (event->button.button) {
        case SDL_BUTTON_LEFT: {
          OnLButtonUp(event->button.x, event->button.y);
          break;
        }
        case SDL_BUTTON_RIGHT: {
          OnRButtonUp(event->button.x, event->button.y);
          break;
        }
        case SDL_BUTTON_MIDDLE: {
          OnMButtonUp(event->button.x, event->button.y);
          break;
        }
      }
      break;
    }

    case SDL_QUIT: {
      OnExit();
      break;
    }

    case SDL_SYSWMEVENT: {
      // Ignore
      break;
    }

    case SDL_VIDEORESIZE: {
      OnResize(event->resize.w, event->resize.h);
      break;
    }

    case SDL_VIDEOEXPOSE: {
      OnExpose();
      break;
    }

    default: {
      OnUser(event->user.type, event->user.code, event->user.data1,
             event->user.data2);
      break;
    }
  }
}

void Event::OnInputFocus() {
  // Pure virtual. Do Nothing
}

void Event::OnInputBlur() {
  // Pure virtual. Do Nothing
}

void Event::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
  // Pure virtual. Do Nothing
}

void Event::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
  // Pure virtual. Do Nothing
}

void Event::OnMouseFocus() {
  // Pure virtual. Do Nothing
}

void Event::OnMouseBlur() {
  // Pure virtual. Do Nothing
}

void Event::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,
                        bool Right, bool Middle) {
  // Pure virtual. Do Nothing
}

void Event::OnMouseWheel(bool up, bool down) {
  // Pure virtual. Do Nothing
}

void Event::OnLButtonDown(int mX, int mY) {
  // Pure virtual. Do Nothing
}

void Event::OnRButtonDown(int mX, int mY) {
  // Pure virtual. Do Nothing
}

void Event::OnMButtonDown(int mX, int mY) {
  // Pure virtual. Do Nothing
}

void Event::OnLButtonUp(int mX, int mY) {
  // Pure virtual. Do Nothing
}

void Event::OnRButtonUp(int mX, int mY) {
  // Pure virtual. Do Nothing
}

void Event::OnMButtonUp(int mX, int mY) {
  // Pure virtual. Do Nothing
}

void Event::OnMinimize() {
  // Pure virtual. Do Nothing
}

void Event::OnRestore() {
  // Pure virtual. Do Nothing
}

void Event::OnResize(int w, int h) {
  // Pure virtual. Do Nothing
}

void Event::OnExpose() {
  // Pure virtual. Do Nothing
}

void Event::OnExit() {
  // Pure virtual. Do Nothing
}

void Event::OnUser(Uint8 type, int code, void* data, void* data2) {
  // Pure virtual. Do Nothing
}

}  // namespace game
