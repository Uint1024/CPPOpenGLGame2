#include <iostream>
#include <cmath>
#include "bullet.h"
#include "graphics/renderer.h"
#include "world.h"

Bullet::Bullet(int x, int y, float angle):
Entity(x, y, 10, 10, 255, 49, 10, texBullet) {
  mDamage = 50;
  mSpeed = 10;
  mMovement.y = std::cos(angle) * mSpeed;
  mMovement.x = std::sin(angle) * mSpeed;
}

void Bullet::update(){
  if(mAlive){
    mAlive = !checkCollisionWithMap();
    auto npcsVector = World::getNpcsVector();
    for(int i = 0 ; i < npcsVector.size(); ++i){
      if(simpleCollisionCheck(npcsVector[i])){
        npcsVector[i]->takeDamage(mDamage);
        mAlive = false;
      }
    }
    applyMovement();
  }
}
