#include "monster.h"

Monster::Monster(glm::vec2 position, glm::vec2 size, glm::vec3 color, 
        int spriteName, int hp, int damage):
Entity(position, size, color, spriteName)
{
  mHp = hp;
  mMaxHp = hp;
  mDamage = damage;
}

