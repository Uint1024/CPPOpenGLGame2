#include <fstream>
#include <glm.hpp>
#include <vector>
#include <iostream>
#include "graphics/renderer.h"
#include "world.h"
#include "entity.h"
#include "player.h"

namespace World{
  static std::vector<Entity*> entities;
  std::vector<Entity*> walls;
  std::vector<Player*> players;
  int mapWidth;
  int mapHeight;
  int tileSize;

  void init() {
    tileSize = 16;
    mapWidth = 40;
    mapHeight = 40;
    int xPos= 0;
    int yPos = 0;
    for(int i = 0 ; i <= mapWidth * mapHeight ; ++i){
      walls.push_back(nullptr);
    }

    std::ifstream file("maps/map1.txt");
    if(file.is_open()){
      file.seekg(0, std::ios::end);
      size_t size = file.tellg();
      std::string mapString(size, ' ');
      file.seekg(0);
      file.read(&mapString[0], size);

      for(int istr = 0 ; istr < size ; ++istr){
        switch(mapString[istr]){
          case '1':
            std::cout << xPos << std::endl;
            walls[yPos * mapWidth + xPos] = new Entity(
              xPos * tileSize, yPos * tileSize,
              tileSize, tileSize,
              100,100,100, texWall);
            ++xPos;
            break;
          case '0':
            ++xPos;
            break;
          case '\n':
            ++yPos;
            xPos = 0;
            break;
          case '\r':
            //Windows return carriage, unused
            //no nothing
            break;
          default:
            std::cout << "World::init(): unknown character" << std::endl;
            break;
        }
      }
    } else {
      std::cout << "Error in World.cpp::init(), can't open map!" << std::endl;
    }


    players.push_back(new Player(100,100,25,25,255,255,255));

  }

  void update() {
    //update each entity's component
    for(Player* player : players){
      player->update();
    }
  }

  std::vector<Entity*>& getEntities(){
    return entities;
  }

  std::vector<Player*>& getPlayers(){
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
