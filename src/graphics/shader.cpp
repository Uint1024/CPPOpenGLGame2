#include <iostream>
#include <GL/glew.h>

#include "graphics/shader.h"

Shader::Shader(const int shaderType, const GLchar* fileName){
  std::cout << "oh" << std::endl;
  id_ = glCreateShader(shaderType);
  std::cout << "oh" << std::endl;
  GLchar* shaderSource = OpenGLUtils::readFileToCString(fileName);
  std::cout << "oh" << std::endl;
  std::cout << "ultrea wtf?" << std::endl;
  glShaderSource(id_, 1, &shaderSource, NULL);
  std::cout << "oh" << std::endl;
  glCompileShader(id_);
  std::cout << "wtf" << std::endl;
  OpenGLUtils::checkShaderCompilationStatus(id_);
  std::cout << "wtf" << std::endl;
  free(shaderSource);
  std::cout << "wtf" << std::endl;
}
