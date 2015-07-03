#include <iostream>
#include <cmath>
#include "player.h"
#include "graphics/renderer.h"
#include "world.h"
#include "weapon.h"

Player::Player(int x, int y, int w, int h, int r, int g, int b) :
Entity(x,y,w,h,r,g,b,texPlayer),
mCurrentWeapon(new Weapon(weaponRevolver)){
  mPlayerId = 0;
  std::cout << "Creating a player " << mPlayerId << std::endl;
  
}

void Player::update(){
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
    double angle = std::atan2(Input::getMouseWorldPositionX() - mPosition.x,
        Input::getMouseWorldPositionY() - mPosition.y);
    mCurrentWeapon->tryToShoot(mPosition, angle);
    std::cout << angle + glm::half_pi<float>() << std::endl;

  }
}
