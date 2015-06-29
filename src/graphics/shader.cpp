#include <GL/glew.h>

#include "graphics/shader.h"

Shader::Shader(const int shaderType, const GLchar* fileName){
  id_ = glCreateShader(shaderType);
  GLchar* shaderSource = OpenGLUtils::readFileToCString(fileName);
  glShaderSource(id_, 1, &shaderSource, NULL);
  glCompileShader(id_);
  OpenGLUtils::checkShaderCompilationStatus(id_);
  free(shaderSource);
}
