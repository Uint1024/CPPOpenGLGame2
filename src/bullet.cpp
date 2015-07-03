#include <iostream>
#include <cmath>
#include "bullet.h"
#include "graphics/renderer.h"

Bullet::Bullet(int x, int y, float angle):
Entity(x, y, 10, 10, 255, 49, 10, texBullet) {
  mSpeed = 10;
  mMovement.y = std::cos(angle) * mSpeed;
  mMovement.x = std::sin(angle) * mSpeed;
  
}

void Bullet::update(){
  if(mAlive){
    mAlive = !checkCollisionWithMap();
    applyMovement();
  }
}

int Bullet::getDamage(){
  return mDamage;
}
