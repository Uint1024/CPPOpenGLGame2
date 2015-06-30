#include <glm.hpp>
#include "entity.h"
#include "input.h"

#ifndef PLAYER_H
#define PLAYER_H
class Player : public Entity
{
  private:
    //kind a KeyBinding enum to a SDL_SCANCODE
    int mPlayerId;
    //Weapon* mCurrentWeapon;
    //std::array<Weapon*, 10> mWeaponInventory;
    
  public:
    Player(int x, int y, int w, int h, int r, int g, int b);
    update();

};

#endif
