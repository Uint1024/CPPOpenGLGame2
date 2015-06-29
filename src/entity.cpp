#include <iostream>
#include "entity.h"
#include "world.h"


Entity::Entity(glm::vec2 position, glm::vec2 size, glm::vec3 color) :
mPosition(position),
mSize(size),
mColor(color){
  
}

Entity::Entity(int x, int y, int w, int h, int r, int g, int b) :
  Entity(glm::vec2(x,y), glm::vec2(w,h), glm::vec3(r,g,b)){
  std::cout << "Constructing entity with " << mPosition.x << std::endl;

}
Entity::~Entity(){
  
}

