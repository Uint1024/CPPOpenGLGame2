#include <glm.hpp>
#include "monster.h"

#ifndef MUTANT_H
#define MUTANT_H
class Mutant : public Monster
{
  private:
    
  public:
    Mutant(glm::vec2 position);
    void update();
};

#endif
