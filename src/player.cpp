#include <iostream>
#include "player.h"
#include "graphics/renderer.h"

Player::Player(int x, int y, int w, int h, int r, int g, int b) :
Entity(x,y,w,h,r,g,b,texPlayer){
  mPlayerId = 0;
  std::cout << "Creating a player " << mPlayerId << std::endl;
}

Player::update(){
  mMovement.x = 0;
  mMovement.y = 0;
  if(Input::playerIsKeyDown(mPlayerId, Key::Right)){
    mMovement.x = 5;
  }
  if(Input::playerIsKeyDown(mPlayerId, Key::Left)){
    mMovement.x = -5;
  }
  if(Input::playerIsKeyDown(mPlayerId, Key::Down)){
    mMovement.y = 5;
  }
  if(Input::playerIsKeyDown(mPlayerId, Key::Up)){
    mMovement.y = -5;
  }
  
  checkCollisionWithMap();
  applyMovement();

  if(Input::playerIsKeyDown(mPlayerId, Key::Shoot)){

  }
}
