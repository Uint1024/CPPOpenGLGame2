#include <GL/glew.h>
#include "graphics/shader.h"

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
class ShaderProgram
{
  private:
    GLuint id_;
    
  public:
    ShaderProgram(Shader& shader1, Shader& shader2);
    void use();
    GLuint getId() {
      return id_;
    }

};
#endif
