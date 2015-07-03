#include <cmath>
#include "weapon.h"
#include "world.h"

Weapon::Weapon(eWeapon type){
  mType = type;
  switch(type){
    case weaponRevolver:
      mDamage = 10;
      mBulletSpeed = 10;
      mShootingDelay = 200;
      mLastShot = 0;
      mReloadTime = 2000;
      mLastReload = 0;
      mBullets = 12;
      mMaxBullets = 12;
      break;
    default:
      std::cout << "Weapon::Weapon() : unknown weapon!" << std::endl;
      break;
  }
}
void Weapon::tryToShoot(glm::vec2 position, float angle){
  int currentTime = SDL_GetTicks();
  if(currentTime - mLastShot > mShootingDelay){

    mLastShot = currentTime; 

    if(mType == weaponRevolver){
      //first we need to figure out the position of the "barrel"
      //first bullet
      /*
      float angleCorrection = angle + glm::half_pi<float>();
      int distance = 10;
      int positionX = position.x + std::sin(angleCorrection) * distance;
      int positionY = position.y + std::cos(angleCorrection) * distance;
      World::createBullet(positionX, positionY, angle);

      angleCorrection = angle - glm::half_pi<float>();
      positionX = position.x + std::sin(angleCorrection) * distance;
      positionY = position.y + std::cos(angleCorrection) * distance;
      World::createBullet(positionX, positionY, angle);
      */
      
    }
  }
}
