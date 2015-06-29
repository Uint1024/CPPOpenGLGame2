#include <SDL_opengl.h>
#include "SDL.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

namespace OpenGLUtils {
  GLchar* readFileToCString(const char* fileName);
  void checkShaderCompilationStatus(GLuint shaderId);
  void checkProgramLinkStatus(GLuint program);
}

namespace Renderer{
  void init();
  void render();
  SDL_Window* getWindow();
  SDL_Renderer* getRenderer();
  void drawRectangle(glm::vec2 position, glm::vec2 size, glm::vec3 color);

}


