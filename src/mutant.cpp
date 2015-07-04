#include <cmath>
#include <iostream>
#include "world.h"
#include "mutant.h"
#include "player.h"
#include "graphics/renderer.h"

Mutant::Mutant(glm::vec2 position):
Monster(position, glm::vec2(20,20), glm::vec3(50,50,50), texMutant){
  
  
}


void Mutant::update(){
  //Basic AI: stay still until it sees a player
  //90° fov
  float lowerAngle = mAngle - 0.785f;
  float higherAngle = mAngle + 0.785f;

  Player* player1 = World::getPlayers()[0];

  //calculating angle to player
  //float angleToPlayer = std::atan2(player1.getPosition.x - mPosition.x,
   //   player1.getPosition.y, mPosition.y);
  float opposite = (player1->getPosition().x - mPosition.x);
  float adjacent =player1->getPosition().y - mPosition.y; 
  float angle = std::atan2(opposite, adjacent);

  std::cout << angle << std::endl;

  mMovement.x = std::sin(angle) * 5;
  mMovement.y = std::cos(angle) * 5;

  checkCollisionWithMap();
  checkCollisionWithNpcs();
  applyMovement();

}
