#include "input.h"
#include <array>
#include <iostream>
#include <SDL.h>
#include "world.h"
#include "entity.h"

#include "graphics/renderer.h"


namespace Input{
  SDL_Event e;
  //bool keyDown[300] = {false};
  std::array<bool, 300> keyDown = {false};
  std::array<bool, 15> mouseButtonDown = {false};
  int mouseX = 0;
  int mouseY = 0;
  int mouseWorldPositionX = 0;
  int mouseWorldPositionY = 0;

  //key bindings for 4 players :
  //bind a key to a controller type (keyboard, mouse, gamepad...) 
  std::array<std::array<ControllerType, (int)Key::NumKeys>, 4> keyControllerType;
  //bind one of the controller's key/button to a game key
  std::array<std::array<int, (int)Key::NumKeys>, 4> keyBindings;


  void init() {
    int playerId = 0;
    keyBindings[playerId][(int)Key::Right] =        SDL_SCANCODE_D;
    keyBindings[playerId][(int)Key::Down] =         SDL_SCANCODE_S;
    keyBindings[playerId][(int)Key::Left] =         SDL_SCANCODE_A;
    keyBindings[playerId][(int)Key::Up] =           SDL_SCANCODE_W;
    keyBindings[playerId][(int)Key::Shoot] =        SDL_BUTTON_LEFT;

    keyControllerType[playerId][(int)Key::Right] =  ControllerType::Keyboard;
    keyControllerType[playerId][(int)Key::Down] =   ControllerType::Keyboard;
    keyControllerType[playerId][(int)Key::Left] =   ControllerType::Keyboard;
    keyControllerType[playerId][(int)Key::Up] =     ControllerType::Keyboard;
    keyControllerType[playerId][(int)Key::Shoot] =  ControllerType::Mouse;

  }

  void pollEvents(bool& runGame) {
    while(SDL_PollEvent(&e)){
      switch(e.type){
        case SDL_QUIT:
          runGame = false;
          break;
        case SDL_KEYDOWN:
          if( e.key.keysym.scancode == SDL_SCANCODE_L ||
              e.key.keysym.scancode == SDL_SCANCODE_F6){
            runGame = false;
          }
          keyDown[e.key.keysym.scancode] =   true;
          break;
        case SDL_KEYUP:
          keyDown[e.key.keysym.scancode] =   false;
          break;
        case SDL_MOUSEBUTTONDOWN:
          mouseButtonDown[e.button.button] = true;
          break;
        case SDL_MOUSEBUTTONUP:
          mouseButtonDown[e.button.button] = false;
          break;
      }
    }

    SDL_GetMouseState(&mouseX, &mouseY);
    mouseWorldPositionX = mouseX + Renderer::getCameraX() - Renderer::getWindowWidth()/2;
    mouseWorldPositionY = mouseY + Renderer::getCameraY() - Renderer::getWindowHeight()/2;
  }

  bool isKeyDown(int scancode){
    //return keyDown[scancode];
  }

  bool playerIsKeyDown(int playerId, Key keyId){
    if(keyControllerType[playerId][(int)keyId] == ControllerType::Keyboard){
      return keyDown[keyBindings[playerId][(int)keyId]];  
    }
    else if(keyControllerType[playerId][(int)keyId] == 
        ControllerType::Mouse){
      return mouseButtonDown[keyBindings[playerId][(int)keyId]];
    }
    else {
      std::cout << "Input::playerIsKeyDown(): unknown key!" << std::endl;
    }
  }

  int getMouseX(){
    return mouseX;
  }
  int getMouseY(){
    return mouseY;
  }
  int getMouseWorldPositionX(){
    return mouseWorldPositionX;
  }
  int getMouseWorldPositionY(){
    return mouseWorldPositionY;
  }
}


