#include <iostream>
#include "entity.h"
#include "world.h"


Entity::Entity(glm::vec2 position, glm::vec2 size, glm::vec3 color,
    int spriteName) :
mPosition(position),
mSize(size),
mColor(color),
mMovement(glm::vec2(0.0f, 0.0f)),
mSpriteName(spriteName){
  
}

Entity::Entity(int x, int y, int w, int h, int r, int g, int b,
    int spriteName) :
  Entity(glm::vec2(x,y), glm::vec2(w,h), glm::vec3(r,g,b),
      spriteName){
  std::cout << "Constructing entity with sprite " << mSpriteName << std::endl;

}
Entity::~Entity(){
  
}

void Entity::checkCollisionWithMap(){
  int minX, maxX, minY, maxY;
  Entity* pWallFound = nullptr;
  auto rWalls = World::getWalls();
  if(mMovement.x < 0){
    maxX = mPosition.x / World::getTileSize();
    minY = mPosition.y / World::getTileSize();
    maxY = (mPosition.y + mSize.y - 1) /
      World::getTileSize();
    if(mPosition.x + mMovement.x < 0){
      mMovement.x = 0;
    }
    for(int x = maxX ; x >= 0 && !pWallFound ; --x){
      for(int y = minY ; y <= maxY && !pWallFound ; ++y){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
          std::cout << "Found wall at" << x << ":" << y << std::endl;
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = (pWallFound->getPosition().x +
          pWallFound->getSize().x) - mPosition.x;
        std::cout << "Distance = " << distance << ", mMovement.x = " << mMovement.x << std::endl;
      if(mMovement.x < distance){
        mMovement.x = distance;
      }
    }
  }
  pWallFound = nullptr;
  if(mMovement.x > 0){
    minX = (mPosition.x + mSize.x) / 
      World::getTileSize();
    minY = mPosition.y / World::getTileSize();
    maxY = (mPosition.y + mSize.y - 1) /
      World::getTileSize();
    if(mPosition.x + mMovement.x +mSize.x > 
        World::getTileSize() * World::getMapWidth()){
      mMovement.x = 0;
    }
    for(int x = minX ; x < World::getMapWidth() && !pWallFound; ++x){
      for(int y = minY ; y <= maxY && !pWallFound ; ++y){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
          std::cout << "Found wall at" << x << ":" << y << std::endl;
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = pWallFound->getPosition().x -
        (mPosition.x + mSize.x);
      std::cout << "Distance = " << distance << ", mMovement.x = " << mMovement.x << std::endl;
      if(mMovement.x > distance){
        mMovement.x = distance;
      }
    }
  }

  pWallFound = nullptr;
  if(mMovement.y < 0){
    maxY = mPosition.y / World::getTileSize();
    minX = mPosition.x / World::getTileSize();
    maxX = (mPosition.x + mSize.x - 1) /
      World::getTileSize();
    if(mPosition.y + mMovement.y < 0){
      mMovement.y = 0;
    }
    for(int y = maxY ; y >= 0 && !pWallFound; --y){
      for(int x = minX ; x <= maxX && !pWallFound ; ++x){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
          std::cout << "Found wall at" << x << ":" << y << std::endl;
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = (pWallFound->getPosition().y +
          pWallFound->getSize().y) - mPosition.y;
        std::cout << "Distance = " << distance << ", mMovement.x = " << mMovement.x << std::endl;
      if(mMovement.y < distance){
        mMovement.y = distance;
      }
    }
  }

  pWallFound = nullptr;
  if(mMovement.y > 0){
    
    minY = (mPosition.y + mSize.y) / 
      World::getTileSize();
    minX = mPosition.x / World::getTileSize();
    maxX = (mPosition.x + mSize.x - 1) /
      World::getTileSize();
    if(mPosition.y + mMovement.y > World::getTileSize() * World::getMapWidth()){
      mMovement.y = 0;
    }
    for(int y = minY ; y < World::getMapHeight() && !pWallFound; ++y){
      for(int x = minX ; x <= maxX  && !pWallFound; ++x){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
          std::cout << "Found wall at" << x << ":" << y << std::endl;
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = pWallFound->getPosition().y -
        (mPosition.y + mSize.y);
      std::cout << "Distance = " << distance << ", mMovement.y = " << mMovement.x << std::endl;
      if(mMovement.y > distance){
        mMovement.y = distance;
      }
    }
  }

}


void Entity::applyMovement(){
  mPosition += mMovement;
}

void Entity::setMovement(float x, float y){
  mMovement.x = x;
  mMovement.y = y;
}
