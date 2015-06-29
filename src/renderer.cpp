#define GLM_FORCE_RADIANS

#include <iostream>
#include <fstream>
#include "SDL.h"
#include <glm.hpp>

#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include "renderer.h"


namespace Renderer{

  static SDL_Window* sdlWindow_;
  static SDL_Renderer* sdlRenderer_;
  static int screen_width_;
  static int screen_height_;
  GLfloat triangleVertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f,  -0.5f, 0.0f,
    0.0f,  0.5f,  0.0f
  };
  GLuint triangleVbo;


  /*Don't forget to free() the point after usage!*/
  GLchar* ReadFileToCString(const char* fileName){
    std::ifstream file(fileName);
    if(file.is_open()){
      file.seekg(0, file.end);
      size_t fileLength = file.tellg();
      GLchar* buffer = (GLchar*) malloc (fileLength);
      file.seekg(0, file.beg);
      file.read(buffer, fileLength);
      file.close();


      return buffer;
    } else {
      return nullptr;
    }
  }

  void Init(){
    GLchar* shaderSource = ReadFileToCString("vertex_shader.gl");
    std::cout << shaderSource << std::endl;
    free(shaderSource);

    screen_width_ =  700;
    screen_height_ = 400;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    sdlWindow_ = SDL_CreateWindow("Test", 50,50,600,400, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(sdlWindow_);

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();

    if(glewError != GLEW_OK)
    {
      std::cout << "Error initializing GLEW!" << glewGetErrorString(glewError) << std::endl;
    }
    else
    {
      std::cout << "Glew OK" << std::endl;
    }

    glViewport( 0.f, 0.f, screen_width_, screen_height_);
    glEnable(GL_DEPTH_TEST);

    //generate buffer at triangleVbo (which is an id)
    glGenBuffers(1, &triangleVbo);
    //bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, triangleVbo);
    //put array triangleVertices into the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW); 


  }


  void Render(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //do rendering stuff I guess
    //
    SDL_GL_SwapWindow(sdlWindow_);
  }

  SDL_Window* GetWindow(){
    return sdlWindow_; 
  }

  SDL_Renderer* GetRenderer(){
    return sdlRenderer_; 
  }
}
