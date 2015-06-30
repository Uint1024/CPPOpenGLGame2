#include <vector>
class Entity;
class Player;

namespace World{
  void init();
  void update();
  std::vector<Entity*>& getEntities();
  std::vector<Player*>& getPlayers();
  std::vector<Entity*>& getWalls();
  int getTileSize();
  int getMapWidth();
  int getMapHeight();
}

