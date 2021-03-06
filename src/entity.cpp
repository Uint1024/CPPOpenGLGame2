#include <iostream>
#include "entity.h"
#include "world.h"


Entity::Entity(glm::vec2 position, glm::vec2 size, glm::vec3 color,
    int spriteName) :
mPosition(position),
mSize(size),
mColor(color),
mMovement(glm::vec2(0.0f, 0.0f)),
mSpriteName(spriteName),
mAlive(true){
  
}

Entity::Entity(int x, int y, int w, int h, int r, int g, int b,
    int spriteName) :
  Entity(glm::vec2(x,y), glm::vec2(w,h), glm::vec3(r,g,b),
      spriteName){
  std::cout << "Constructing entity with sprite " << mSpriteName << std::endl;

}
Entity::~Entity(){
  
}

bool Entity::checkCollisionWithNpcs(){
  int minX, maxX, minY, maxY;
  Entity* pNpcFound = nullptr;
  bool collision = false;
  auto npcsVector = World::getNpcsVector();
  if(mMovement.x < 0){
    maxX = mPosition.x;
    minY = mPosition.y;
    maxY = (mPosition.y + mSize.y - 1);
    int maxXFound = 0;
    
    for(int i = 0 ; i < npcsVector.size()  ; i++){
      if( npcsVector[i] != this &&
          static_cast<int>(npcsVector[i]->getPosition().y + npcsVector[i]->mSize.y) > minY &&
          static_cast<int>(npcsVector[i]->getPosition().y) < maxY &&
          static_cast<int>(npcsVector[i]->getPosition().x + npcsVector[i]->mSize.x) <= maxX &&
          maxXFound < npcsVector[i]->getPosition().x + npcsVector[i]->mSize.x){
          maxXFound = npcsVector[i]->getPosition().x + npcsVector[i]->mSize.x;
          pNpcFound = npcsVector[i];
       }
    }
    if(pNpcFound != nullptr){
      int distance = (pNpcFound->getPosition().x +
          pNpcFound->getSize().x) - mPosition.x; 
      if(mMovement.x < distance){

        collision = true;
        mMovement.x = distance;
      }
    }
  }
  pNpcFound = nullptr;
  if(mMovement.x > 0){
    int minXFound = 1000000;
    minX = mPosition.x + mSize.x;
    minY = mPosition.y;
    maxY = (mPosition.y + mSize.y - 1);
    
    for(int i = 0 ; i < npcsVector.size()  ; i++){
      if(npcsVector[i] != this &&
          static_cast<int>(npcsVector[i]->getPosition().y + npcsVector[i]->mSize.y) > minY &&
          static_cast<int>(npcsVector[i]->getPosition().y) < maxY &&
          static_cast<int>(npcsVector[i]->getPosition().x) >= minX &&
          minXFound > npcsVector[i]->getPosition().x){
          minXFound = npcsVector[i]->getPosition().x;
          pNpcFound = npcsVector[i];
       }
    }
    if(pNpcFound != nullptr){
      int distance = pNpcFound->getPosition().x 
          - (mPosition.x + mSize.x); 
      if(mMovement.x > distance){
        collision = true;
        mMovement.x = distance;
      }
    }
  }
  pNpcFound = nullptr;
  
  if(mMovement.y < 0){
    maxX = mPosition.x + mSize.x;
    minX = mPosition.x; 
    int maxYFound = 0;
    
    for(int i = 0 ; i < npcsVector.size()  ; i++){
      if( npcsVector[i]!=this &&
          static_cast<int>(npcsVector[i]->getPosition().y) <= mPosition.y &&
          static_cast<int>(npcsVector[i]->getPosition().x + npcsVector[i]->mSize.x) > minX &&
          static_cast<int>(npcsVector[i]->getPosition().x < maxX) &&
          maxYFound < npcsVector[i]->getPosition().y + npcsVector[i]->mSize.y){
          maxYFound = npcsVector[i]->getPosition().y + npcsVector[i]->mSize.y;
          pNpcFound = npcsVector[i];
       }
    }
    
    if(pNpcFound != nullptr){
      int distance = maxYFound - mPosition.y;
      if(mMovement.y < distance + 1){
        collision = true;
        mMovement.y = distance;
      }
    }
      
  }
  pNpcFound = nullptr;
  
  if(mMovement.y > 0){
    int minYFound = 100000000;
    maxX = mPosition.x + mSize.x; 
    minX = mPosition.x;
    minY = mPosition.y + mSize.y;
    
    for(int i = 0 ; i < npcsVector.size()  ; i++){
      if( npcsVector[i] != this &&
          static_cast<int>(npcsVector[i]->getPosition().y) >= minY &&
          static_cast<int>(npcsVector[i]->getPosition().x) < maxX &&
          static_cast<int>(npcsVector[i]->getPosition().x + npcsVector[i]->mSize.x) > minX &&
          minYFound > npcsVector[i]->getPosition().y){

          minYFound = npcsVector[i]->getPosition().y;
          pNpcFound = npcsVector[i];
       }
    }
    
    if(pNpcFound != nullptr){
      int distance = pNpcFound->getPosition().y 
          - (mPosition.y + mSize.y); 
      if(mMovement.y > distance){
        collision = true;
        mMovement.y = distance;
      }
    }
  }

  return collision;
}

bool Entity::checkCollisionWithMap(){
  int minX, maxX, minY, maxY;
  Entity* pWallFound = nullptr;
  bool collision = false;
  auto rWalls = World::getWallsVector();
  if(mMovement.x < 0){
    maxX = mPosition.x / World::getTileSize();
    minY = mPosition.y / World::getTileSize();
    maxY = (mPosition.y + mSize.y - 1) /
      World::getTileSize();
    if(mPosition.x + mMovement.x < 0){
      collision = true;
      mMovement.x = 0;
    }
    for(int x = maxX ; x >= 0 && !pWallFound ; --x){
      for(int y = minY ; y <= maxY && !pWallFound ; ++y){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = (pWallFound->getPosition().x +
          pWallFound->getSize().x) - mPosition.x;
      if(mMovement.x < distance){
        collision = true;
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
      collision = true;
      mMovement.x = 0;
    }
    for(int x = minX ; x < World::getMapWidth() && !pWallFound; ++x){
      for(int y = minY ; y <= maxY && !pWallFound ; ++y){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = pWallFound->getPosition().x -
        (mPosition.x + mSize.x);
      if(mMovement.x > distance){
        collision = true;
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
      collision = true;
      mMovement.y = 0;
    }
    for(int y = maxY ; y >= 0 && !pWallFound; --y){
      for(int x = minX ; x <= maxX && !pWallFound ; ++x){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = (pWallFound->getPosition().y +
          pWallFound->getSize().y) - mPosition.y;
      if(mMovement.y < distance){
      collision = true;
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
      collision = true;
      mMovement.y = 0;
    }
    for(int y = minY ; y < World::getMapHeight() && !pWallFound; ++y){
      for(int x = minX ; x <= maxX  && !pWallFound; ++x){
        if(rWalls[y * World::getMapWidth() + x] != nullptr){
          pWallFound = rWalls[y * World::getMapWidth() + x];
        }
      }
    }
    if(pWallFound != nullptr){
      int distance = pWallFound->getPosition().y -
        (mPosition.y + mSize.y);
      if(mMovement.y > distance){
      collision = true;
        mMovement.y = distance;
      }
    }
  }

  return collision;
}


bool Entity::simpleCollisionCheck(Entity* e){
  if(e->mPosition.y > mPosition.y + mSize.y ||
      e->mPosition.y + e->mSize.y < mPosition.y ||
      e->mPosition.x > mPosition.x + mSize.x ||
      e->mPosition.x + mSize.x < mPosition.x){
      return false;
   }
  return true;
}
void Entity::correctMovementZero(){
  if(mMovement.x < 0.01f &&
      mMovement.x > -0.01f){
    mMovement.x = 0;
  }
  if(mMovement.y < 0.01f &&
      mMovement.y > -0.01f){
    mMovement.y = 0;
  }
}
void Entity::applyMovement(){
  mPosition += mMovement;
}

void Entity::takeDamage(int damage){
  mHp -= damage;
  if(mHp < 0){
    mAlive = false;
  }
}

void Entity::setMovement(float x, float y){
  mMovement.x = x;
  mMovement.y = y;
}

void Entity::update(){
  std::cout << "This should never be called. Overwrite in children classes."
    << std::endl;
}

bool Entity::isAlive(){
  return mAlive;
}
