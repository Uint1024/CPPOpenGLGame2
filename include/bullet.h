#include "entity.h"

#ifndef BULLET_H
#define BULLET_H
class Bullet : public Entity
{
  private:
  public:
    Bullet(int x, int y, float angle);
    int getDamage();
    void update();

};
#endif
