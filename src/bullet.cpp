#include <cmath>
#include "bullet.h"
#include "graphics/renderer.h"

Bullet::Bullet(int x, int y, float angle):
Entity(x, y, 10, 10, 255, 49, 10, texBullet) {
  mAlive = false;

  mMovement.x = std::cos(angle);
  mMovement.y = std::sin(angle);
  
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
