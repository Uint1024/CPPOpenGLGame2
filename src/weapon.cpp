#include <gtc/constants.hpp>
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
      mBulletSize = glm::vec2(10, 10);
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
      //on doit trouver le centre des balles
      position.x -= mBulletSize.x / 2; 
      position.y -= mBulletSize.y / 2; 

      int distance = 6;
      float angleCorrection = angle + glm::half_pi<float>();
      glm::vec2 correction;
      correction.x = std::sin(angleCorrection) * distance;
      correction.y = std::cos(angleCorrection) * distance;
      int positionX = position.x + correction.x;
      int positionY = position.y + correction.y;
      World::createBullet(positionX, positionY, angle);
      std::cout << "Angle = " << angle << ", angle correction = " << 
        angleCorrection << ", correctionx = " <<
        correction.x << ", correctiony = " << correction.y << std::endl;
      std::cout << position.x << std::endl;
      

      distance = 6;
      angleCorrection = angle - glm::half_pi<float>();
      correction.x = std::sin(angleCorrection) * distance;
      correction.y = std::cos(angleCorrection) * distance;
      positionX = position.x + correction.x;
      positionY = position.y + correction.y;
      World::createBullet(positionX, positionY, angle);
      std::cout << "Angle = " << angle << ", angle correction = " << 
        angleCorrection << ", correctionx = " <<
        correction.x << ", correctiony = " << correction.y << std::endl;
      std::cout << position.x << std::endl;
      
      
    }
  }
}
