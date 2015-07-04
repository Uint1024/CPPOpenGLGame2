#include <glm.hpp>
#include <entity.h>

#ifndef MONSTER_H
#define MONSTER_H
enum eMonsterType {
  monsterMutant,
  monsterHellGuardians,
  nbOfMonsterTypes
};

class Monster : public Entity
{
  private:
    int mHp;
    int mMaxHp;
    int mDamage; //close combat damage, ie touching the mob

  public:
    Monster(glm::vec2 position, glm::vec2 size, glm::vec3 color, 
        int spriteName);
    virtual void update() = 0;
};
#endif
