#include <SDL.h>
#include <iostream>
#include <glm.hpp>

#ifndef WEAPON_H
#define WEAPON_H
enum eWeapon {
  //double barreled
  weaponRevolver,
  weaponShotgun,
  weaponTripleBarrelShotgun,
  weaponBow,
  weaponRockLauncher,
  weaponLaser
};

class Weapon
{
  private:
    eWeapon mType;
    int mDamage;
    float mBulletSpeed;
    int mShootingDelay; //in ms
    int mLastShot;
    int mReloadTime;
    int mLastReload;
    bool mReloading;
    int mBullets;
    int mMaxBullets;
    glm::vec2 mBulletSize;
    
  public:
    Weapon(eWeapon type);
    void tryToShoot(glm::vec2 position, float angle);
};

#endif
