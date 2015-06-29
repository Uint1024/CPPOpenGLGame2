#include <iostream>
#include <SDL.h>
#include "world.h"
#include "entity.h"

namespace Input{
  SDL_Event e;
  bool keyDown[300] = {false};

  void init() {
  }

  void pollEvents(bool& runGame) {
    while(SDL_PollEvent(&e)){
      switch(e.type){
        case SDL_QUIT:
          runGame = false;
          break;
        case SDL_KEYDOWN:
          keyDown[e.key.keysym.scancode] = true;
          break;
        case SDL_KEYUP:
          keyDown[e.key.keysym.scancode] = false;
          break;
      }
    }
    int xMov, yMov = 0;

    if(keyDown[SDL_SCANCODE_S]){
      //World::getPlayers()[0]->moveY(5);
      yMov = 5;
    }
    if(keyDown[SDL_SCANCODE_W]){
      //World::getPlayers()[0]->moveY(-5);
      yMov = -5;
    }
    if(keyDown[SDL_SCANCODE_A]){
      //World::getPlayers()[0]->moveX(-5);
      xMov = -5;
    }
    if(keyDown[SDL_SCANCODE_D]){
      //World::getPlayers()[0]->moveX(5);
      xMov = 5;
    }
    
    auto pPlayer1 = World::getPlayers()[0];
    auto rWalls = World::getWalls();
    
    //collision algorithm
    //get coordinate of forward facing edge 
    int minX, maxX, minY, maxY;
    Entity* pWallFound = nullptr;
    if(xMov < 0){
      maxX = pPlayer1->getPosition().x / World::getTileSize();
      minY = pPlayer1->getPosition().y / World::getTileSize();
      maxY = (pPlayer1->getPosition().y + pPlayer1->getSize().y) /
        World::getTileSize();
      for(int y = minY ; y < maxY && !pWallFound ; ++y){
        for(int x = maxX ; x > 0 && !pWallFound ; --x){
          if(rWalls[y * World::getMapWidth() + x] != nullptr){
            pWallFound = rWalls[y * World::getMapWidth() + x];
            std::cout << "Found wall at" << x << ":" << y << std::endl;
          }
        }
      }
      if(pWallFound != nullptr){
        int distance = (pWallFound->getPosition().x +
            pWallFound->getSize().x) - pPlayer1->getPosition().x;
          std::cout << "Distance = " << distance << ", xMov = " << xMov << std::endl;
        if(xMov < distance){
          xMov = distance;
        }
      }
    }
    pWallFound = nullptr;
    if(xMov > 0){
      minX = (pPlayer1->getPosition().x + pPlayer1->getSize().x) / 
        World::getTileSize();
      minY = pPlayer1->getPosition().y / World::getTileSize();
      maxY = (pPlayer1->getPosition().y + pPlayer1->getSize().y) /
        World::getTileSize();
      for(int y = minY ; y < maxY && !pWallFound ; ++y){
        for(int x = minX ; x < World::getMapWidth() && !pWallFound; ++x){
          if(rWalls[y * World::getMapWidth() + x] != nullptr){
            pWallFound = rWalls[y * World::getMapWidth() + x];
            std::cout << "Found wall at" << x << ":" << y << std::endl;
          }
        }
      }
      if(pWallFound != nullptr){
        int distance = pWallFound->getPosition().x -
          (pPlayer1->getPosition().x + pPlayer1->getSize().x);
        std::cout << "Distance = " << distance << ", xMov = " << xMov << std::endl;
        if(xMov > distance){
          xMov = distance;
        }
      }
    }
    pWallFound = nullptr;

    if(yMov < 0){
      maxY = pPlayer1->getPosition().y / World::getTileSize();
      minX = pPlayer1->getPosition().x / World::getTileSize();
      maxX = (pPlayer1->getPosition().x + pPlayer1->getSize().x - 1) /
        World::getTileSize();
      std::cout << minX << " " << maxX << std::endl;
      for(int x = minX ; x <= maxX && !pWallFound ; ++x){
        for(int y = maxY ; y >= 0 && !pWallFound; --y){
          if(rWalls[y * World::getMapWidth() + x] != nullptr){
            pWallFound = rWalls[y * World::getMapWidth() + x];
            std::cout << "Found wall at" << x << ":" << y << std::endl;
          }
        }
      }
      if(pWallFound != nullptr){
        int distance = (pWallFound->getPosition().y +
            pWallFound->getSize().y) - pPlayer1->getPosition().y;
          std::cout << "Distance = " << distance << ", xMov = " << xMov << std::endl;
        if(yMov < distance){
          yMov = distance;
        }
      }
    }
    /*if(xMov > 0){
      minX = (pPlayer1->getPosition().x + pPlayer1->getSize().x) / 
        World::getTileSize();
      minY = pPlayer1->getPosition().y / World::getTileSize();
      maxY = (pPlayer1->getPosition().y + pPlayer1->getSize().y) /
        World::getTileSize();
      for(int y = minY ; y < maxY ; ++y && !pWallFound){
        for(int x = minX ; x < World::getMapWidth(); ++x && !pWallFound){
          if(rWalls[y * World::getMapWidth() + x] != nullptr){
            pWallFound = rWalls[y * World::getMapWidth() + x];
            std::cout << "Found wall at" << x << ":" << y << std::endl;
          }
        }
      }
      if(pWallFound != nullptr){
        int distance = pWallFound->getPosition().x -
          (pPlayer1->getPosition().x + pPlayer1->getSize().x);
        std::cout << "Distance = " << distance << ", xMov = " << xMov << std::endl;
        if(xMov > distance){
          xMov = distance;
        }
      }
    }*/
    /*if(xMov < 0){
      int leftCoord = pPlayer1->getPosition().x;
      int leftCoordTile = leftCoord / World::getTileSize();

      //figure out which horizontal row the bbox intersects with
      int minHorizontal = pPlayer1->getPosition().y / World::getTileSize();
      int maxHorizontal = (pPlayer1->getPosition().y + pPlayer1->getSize().y) /
        World::getTileSize();
      
      //scan along the horizontal lines and find first static obstacle
      Entity* pWallFound = nullptr;
      for(int y = minHorizontal ; y < maxHorizontal ; ++y && !pWallFound){
        for(int x = leftCoordTile ; x > 0 ; --x && !pWallFound){
          if(rWalls[y * World::getTileSize() + x] != nullptr){
            pWallFound = rWalls[y * World::getTileSize() + x];
            std::cout << "Found wall at" << x << ":" << y << std::endl;
          }
        }
      }

      //total movement along the direction is minimum between closest wall
      //and amount of movement from input
      int distance = (pWallFound->getPosition().x +
          pWallFound->getSize().x) - pPlayer1->getPosition().x;
        std::cout << "Distance = " << distance << ", xMov = " << xMov << std::endl;
      if(xMov < distance){
        xMov = distance;
      }
    }*/

    pPlayer1->move(xMov, yMov);
    if(keyDown[SDL_SCANCODE_DOWN]){
      World::getPlayers()[1]->moveY(5);
    }
    if(keyDown[SDL_SCANCODE_UP]){
      World::getPlayers()[1]->moveY(-5);
    }
  }

}
