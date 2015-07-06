#include <glm.hpp>
#include <vector>
#include <iostream>
#include "graphics/renderer.h"
#include "world.h"
#include "entity.h"
#include "player.h"
#include "bullet.h"
#include "utils.h"
#include "mutant.h"

namespace World{
  std::vector<Entity*> backgroundMap;
  std::vector<Entity*> wallsVector;
  std::vector<Entity*> bulletsVector;
  std::vector<Player*> players;
  std::vector<Entity*> npcsVector;
  int mapWidth;
  int mapHeight;
  int tileSize;

  void init() {
    tileSize = 40;
    mapWidth = 40;
    mapHeight = 40;
    for(int i = 0 ; i <= mapWidth * mapHeight ; ++i){
      wallsVector.push_back(nullptr);
      backgroundMap.push_back(nullptr);
    }

    int tilePositionX =  0;
    int tilePositionY =  0;
    int pixelPositionX = 0;
    int pixelPositionY = 0;
    int vectorPosition = 0; //position of the tile in the map vectors

    std::string mapString = Utils::readFileToString("maps/map1.foreground");
    for(int istr = 0 ; istr < mapString.size() ; ++istr){
      pixelPositionX = tilePositionX * tileSize;
      pixelPositionY = tilePositionY * tileSize;
      vectorPosition = tilePositionY * mapWidth + tilePositionX;
      switch(mapString[istr]){
        case '1':
          wallsVector[vectorPosition] = new Entity(
            pixelPositionX, pixelPositionY,
            tileSize, tileSize,
            100,100,100, texWall);
          break;
        case '0':
          //empty tile
          break;
        case 'P':
          players.push_back(new Player(pixelPositionX, pixelPositionY,
                25,25,255,255,255));
          break;
        case 'M':
          npcsVector.push_back(new Mutant(glm::vec2(pixelPositionX, 
                  pixelPositionY)));
          break;
        case '\n':
          ++tilePositionY;
          tilePositionX = -1;
          break;
        case '\r':
          //Windows return carriage, unused
          --tilePositionX;
          break;
        default:
          std::cout << "World::init(), foreground, unknown character" << std::endl;
          break;
      }
      ++tilePositionX;
    }

    tilePositionX = 0;
    tilePositionY = 0;
    std::string backgroundMapString = Utils::readFileToString("maps/map1.background");
    for(int istr = 0 ; istr < backgroundMapString.size() ; ++istr){
      pixelPositionX = tilePositionX * tileSize;
      pixelPositionY = tilePositionY * tileSize;
      vectorPosition = tilePositionY * mapWidth + tilePositionX;
      switch(backgroundMapString[istr]){
        case '0':
          backgroundMap[vectorPosition] = new Entity(
            pixelPositionX, pixelPositionY,
            tileSize, tileSize,
            100,100,100, texGround);
          break;
        case '\n':
          ++tilePositionY;
          tilePositionX = -1;
          break;
        case '\r':
          //Windows return carriage, unused
          --tilePositionX;
          break;
        default:
          std::cout << "World::init(), background, unknown character" << std::endl;
          break;
      }
      ++tilePositionX;
    }
  }

  void update() {
    for(Player* player : players){
      player->update();
    }

    for(int i = 0 ; i < bulletsVector.size();){
      bulletsVector[i]->update();
      if(!bulletsVector[i]->isAlive()){
        bulletsVector.erase(bulletsVector.begin()+i);
      }
      else {
        ++i;
      }
    }

    for(int i = 0 ; i < npcsVector.size();){
      npcsVector[i]->update();
      if(!npcsVector[i]->isAlive()){
        npcsVector.erase(npcsVector.begin()+i);
      }
      else {
        ++i;
      }
    }
  }
  
  void createBullet(int x, int y, float angle){
    bulletsVector.push_back(new Bullet(x, y, angle));
    std::cout << "World::createBullet : " << bulletsVector.size() << std::endl;
  }

  std::vector<Player*>& getPlayers(){
    return players;
  }
  std::vector<Entity*>& getWallsVector(){
    return wallsVector;
  }
  std::vector<Entity*>& getBackground(){
    return backgroundMap;
  }
  std::vector<Entity*>& getBulletsVector(){
    return bulletsVector;
  }
  std::vector<Entity*>& getNpcsVector(){
    return npcsVector;
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
