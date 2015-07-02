#include <vector>
class Entity;
class Player;

namespace World{
  void init();
  void update();
  std::vector<Player*>& getPlayers();
  std::vector<Entity*>& getWallsVector();
  std::vector<Entity*>& getBackground();
  int getTileSize();
  int getMapWidth();
  int getMapHeight();
  void createBullet();
}

