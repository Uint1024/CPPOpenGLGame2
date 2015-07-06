#include <glm.hpp>
#include "icontroller.h"
#include <string>

#ifndef ENTITY_H
#define ENTITY_H

//entities are objects that can be drawn on screen
class Entity
{
  protected:
    glm::vec2 mPosition;
    glm::vec2 mMovement;
    glm::vec2 mSize;
    glm::vec3 mColor;
    int mSpriteName;
    float mAngle;
    float mSpeed;
    bool mAlive;
    int mHp;
    int mMaxHp;
    int mDamage;
    //Sprite mSprite;

  public:
    Entity(glm::vec2 position, glm::vec2 size, glm::vec3 color, 
        int spriteName);
    Entity(int x, int y, int w, int h, int r, int g, int b, 
        int spriteName);
    ~Entity();
    bool checkCollisionWithNpcs();
    glm::vec2 getPosition() {
      return mPosition;
    }
    glm::vec2 getSize(){
      return mSize;
    }
    glm::vec3 getColor(){
      return mColor;
    }

    void setMovement(float x, float y);

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
    void applyMovement();

    void moveAbsolute(int x, int y){
      mPosition.x = x;
      mPosition.y = y;
    }

    void setSpriteName(int name){
      mSpriteName = name;
    }

    int getSpriteName(){
      return mSpriteName;
    }

    void correctMovementZero();
    bool simpleCollisionCheck(Entity* e);
    void takeDamage(int damage);

    bool isAlive();

    //check if there's a collision with walls or other entities
    //and set correct mMovement values
    bool checkCollisionWithMap();
    virtual void update();

    //TODO add components...

};
#endif
