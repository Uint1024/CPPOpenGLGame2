#include <iostream>
#include "world.h"
#include "graphics/renderer.h"
#include "input.h"

int main( int argc, char **argv ) {
  Renderer::init();
  Input::init();
  World::init();

  bool runGame = true;
  while(runGame){
    Input::pollEvents(runGame);
    World::update();
    Renderer::render();
  }


}
