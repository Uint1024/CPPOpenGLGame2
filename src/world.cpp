#include <glm.hpp>
#include <vector>
#include <iostream>
#include "world.h"
#include "entity.h"

namespace World{
  static std::vector<Entity*> entities;

  void init() {
    entities.push_back(new Entity(50,50,10,100,50,50,50));

  }

  void update() {
    //update each entity's component
  }

  std::vector<Entity*>& getEntities(){
    return entities;
  }
}
