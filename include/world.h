#include <vector>
class Entity;

namespace World{
  void init();
  void update();
  std::vector<Entity*>& getEntities();
  std::vector<Entity*>& getPlayers();
  std::vector<Entity*>& getWalls();
  int getTileSize();
  int getMapWidth();
  int getMapHeight();
}

