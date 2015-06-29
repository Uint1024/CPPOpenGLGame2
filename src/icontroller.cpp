#include <iostream>
#include "icontroller.h"
#include "world.h"

IController::~IController() {
  
}

IControllerPlayer::IControllerPlayer(){
  
}

void IControllerPlayer::update(World* world){
  std::cout << "Updating player controller." << std::endl;
  world->addRandomBonus();

}

IControllerBonus::IControllerBonus() {
}

void IControllerBonus::update(World* world){
  std::cout << "Updating bonus controller." << std::endl;
}
