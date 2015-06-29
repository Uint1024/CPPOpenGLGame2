#include <glm.hpp>
#include "icontroller.h"

#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
  private:
    glm::vec2 mPosition;
    glm::vec2 mSize;
    glm::vec3 mColor;

  public:
    Entity(glm::vec2 position, glm::vec2 size, glm::vec3 color);
    Entity(int x, int y, int w, int h, int r, int g, int b);
    ~Entity();
    glm::vec2 getPosition() {
      return mPosition;
    }
    glm::vec2 getSize(){
      return mSize;
    }
    glm::vec3 getColor(){
      return mColor;
    }

    void moveY(int movement){
      mPosition.y += movement;
    }

    void moveX(int movement){
      mPosition.x += movement;
    }
    void move(int xMovement, int yMovement) {
      mPosition.y += yMovement;
      mPosition.x += xMovement;
    }

    void moveAbsolute(int x, int y){
      mPosition.x = x;
      mPosition.y = y;
    }

};
#endif
