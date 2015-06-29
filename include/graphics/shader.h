#include <GL/glew.h>
#include "renderer.h"

#ifndef SHADER_H
#define SHADER_H
class Shader
{
  private:
    GLuint id_;
    
  public:
    //shaderType can be GL_VERTEX_SHADER, GL_FRAGMENT_SHADER etc.
    Shader(const int shaderType, const GLchar* fileName);
    GLuint getId() {
      return id_;
    }

};

#endif
