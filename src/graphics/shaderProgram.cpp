#include "graphics/shaderProgram.h"
#include <GL/glew.h>
#include "graphics/renderer.h"

ShaderProgram::ShaderProgram(Shader& shader1, Shader& shader2){

  id_ = glCreateProgram();

  glAttachShader(id_, shader1.getId());
  glAttachShader(id_, shader2.getId());
  glLinkProgram(id_);
  OpenGLUtils::checkProgramLinkStatus(id_);
}

void ShaderProgram::use(){
  glUseProgram(id_);
}
