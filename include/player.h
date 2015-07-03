#include <glm.hpp>
#include <array>
#include "entity.h"
#include "input.h"

#ifndef PLAYER_H
#define PLAYER_H
class Weapon;
class Player : public Entity
{
  private:
    int mPlayerId;
    Weapon* mCurrentWeapon;
    std::array<Weapon*, 10> mWeaponInventory;
    
  public:
    Player(int x, int y, int w, int h, int r, int g, int b);
    virtual void update();

};

#endif
