#include <vector>
class Entity;
class Player;

namespace World{
  void init();
  void update();
  std::vector<Player*>& getPlayers();
  std::vector<Entity*>& getWallsVector();
  std::vector<Entity*>& getBackground();
  std::vector<Entity*>& getBulletsVector();
  std::vector<Entity*>& getNpcsVector();

  int getTileSize();
  int getMapWidth();
  int getMapHeight();
  void createBullet(int x, int y, float angle);
}

