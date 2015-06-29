#include <vector>
class Entity;

namespace World{
  void init();
  void update();
  std::vector<Entity*>& getEntities();
}

