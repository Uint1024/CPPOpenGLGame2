#include <glm.hpp>
#include <vector>
#include <iostream>
#include "graphics/renderer.h"
#include "world.h"
#include "entity.h"

namespace World{
  static std::vector<Entity*> entities;
  std::vector<Entity*> walls;
  std::vector<Entity*> players;
  int mapWidth;
  int mapHeight;
  int tileSize;

  void init() {
    tileSize = 20;
    mapWidth = 40;
    mapHeight = 40;
    for(int x = 0 ; x < mapWidth ; ++x){
      for(int y = 0 ; y < mapHeight ; ++y){
        walls.push_back(nullptr);
        
      }
    }

    int xPos = 2;
    int yPos = 1;
    walls[yPos * mapWidth + xPos] = new Entity(
        xPos * tileSize, yPos * tileSize,
        tileSize, tileSize,
        100,100,100);
    yPos = 2;
    walls[yPos * mapWidth + xPos] = new Entity(
        xPos * tileSize, yPos * tileSize,
        tileSize, tileSize,
        100,100,100);
    yPos = 3;
    walls[yPos * mapWidth + xPos] = new Entity(
        xPos * tileSize, yPos * tileSize,
        tileSize, tileSize,
        100,100,100);
    players.push_back(new Entity(50,50,20,150,200,50,50));
    players.push_back(new Entity(Renderer::getWindowWidth()-50,
          50,20,150,200,50,50));


    //entities.push_back(new Entity(50,50,10,100,50,50,50));

  }

  void update() {
    //update each entity's component
  }

  std::vector<Entity*>& getEntities(){
    return entities;
  }

  std::vector<Entity*>& getPlayers(){
    return players;
  }
  std::vector<Entity*>& getWalls(){
    return walls;
  }
  int getTileSize(){
    return tileSize;
  }
  int getMapWidth(){
    return mapWidth;
  }
  int getMapHeight(){
    return mapHeight;
  }
}
