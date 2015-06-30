#include "input.h"
#include <array>
#include <iostream>
#include <SDL.h>
#include "world.h"
#include "entity.h"



namespace Input{
  SDL_Event e;
  //bool keyDown[300] = {false};
  std::array<bool, 300> keyDown = {false};
  std::array<bool, 15> mouseButtonDown = {false};

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
          keyDown[e.key.keysym.scancode] = true;
          break;
        case SDL_KEYUP:
          keyDown[e.key.keysym.scancode] = false;
          break;
        case SDL_MOUSEBUTTONDOWN:
          mouseButtonDown[e.button.button] = true;
          break;
        case SDL_MOUSEBUTTONUP:
          mouseButtonDown[e.button.button] = false;
          break;
      }
    }
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
}


