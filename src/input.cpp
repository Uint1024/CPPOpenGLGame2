#include <SDL.h>

namespace Input{
  SDL_Event e;
  bool keyDown[300] = {false};

  void init() {
  }

  void pollEvents(bool& runGame) {
    while(SDL_PollEvent(&e)){
      switch(e.type){
        case SDL_QUIT:
          runGame = false;
          break;
        case SDL_KEYDOWN:
          keyDown[e.key.keysym.scancode] = true;
          break;
        case SDL_KEYUP:
          keyDown[e.key.keysym.scancode] = false;
          break;
      }
    }
  }
}
