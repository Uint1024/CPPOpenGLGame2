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
  public:
    Monster(glm::vec2 position, glm::vec2 size, glm::vec3 color, 
        int spriteName, int hp, int damage);
    virtual void update() = 0;
};
#endif
