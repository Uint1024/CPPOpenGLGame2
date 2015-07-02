#include <iostream>
#include <fstream>
#include "utils.h"
namespace Utils {
  //return string from file
  //return empty string if file couldn't be opened
  std::string readFileToString(std::string fileName){
    std::cout << fileName << std::endl;
    std::ifstream file(fileName.c_str());
    if(file.is_open()){
      file.seekg(0, std::ios::end);
      size_t size = file.tellg();
      std::string fileString(size, ' ');
      file.seekg(0);
      file.read(&fileString[0], size);
      return fileString;

    } else {
      std::cout << "Error in World.cpp::init(), can't open map!" << std::endl;
      return std::string("");
    }
  }
}
