#include <iostream>
#include "icontroller.h"
#include "world.h"

IController::~IController() {
  
}


IControllerBonus::IControllerBonus() {
}

void IControllerBonus::update(World* world){
  std::cout << "Updating bonus controller." << std::endl;
}
