#include <iostream>
#include <fstream>
#include <vector>
#include "SDL.h"

#include <GL/glew.h>
#include <SDL_opengl.h>
#include "graphics/renderer.h"
#include "graphics/shader.h"
#include "graphics/shaderProgram.h"
#include "entity.h"
#include "world.h"

namespace OpenGLUtils {
  /*Don't forget to free() the point after usage!*/
  GLchar* readFileToCString(const char* fileName){
    std::ifstream file(fileName, std::ifstream::binary);
    if(file.is_open()){
      file.seekg(0, file.end);
      size_t fileLength = file.tellg();
      GLchar* buffer = new GLchar[fileLength];
      size_t position = 0;
      file.seekg(0, file.beg);
      while(!file.eof() && position < fileLength){
        file.get(buffer[position]);
        position++;
      }
      buffer[position] = '\0';
      return buffer;
    } else {
      std::cout << "Error during ReadFileToCString, can't find " << fileName << std::endl;
      return nullptr;
    }
  }

  void checkShaderCompilationStatus(GLuint shaderId){
    GLint success =  GL_FALSE;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){
      printf("Error during compilation of shader %i.\n", shaderId);
      int infoLength = 0;
      int maxLength = 0;

      glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLength);
      char infoLog[infoLength];
      glGetShaderInfoLog(shaderId, infoLength, &infoLength, infoLog);
      printf("%s\n", infoLog);
    }
    else {
      printf("Compilation of shader %i successful.\n", shaderId);
    }
  }

  void checkProgramLinkStatus(GLuint program){
		GLint program_success = GL_TRUE;
		glGetProgramiv(program, GL_LINK_STATUS, &program_success);
		if(program_success != GL_TRUE){
			printf("Error linking program %d!\n", program);

			int info_length = 0;
			int max_length = 0;

			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &max_length);
			char info_log[max_length];
			glGetProgramInfoLog(program, max_length, &info_length, info_log);
			if(info_length > 0){
				printf("%s\n", info_log);
			}
		}
		else{
			printf("Linking of program %i successful.\n", program);
		}
	}
}
namespace Renderer{

  static SDL_Window* sdlWindow_;
  static SDL_Renderer* sdlRenderer_;
  float windowWidth;
  float windowHeight;
  GLfloat triangleVertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f,  -0.5f, 0.0f,
    0.0f,  0.5f,  0.0f
  };
  GLfloat rectangleVertices[] = {
  0.0f, 0.0f, 0.0f,//top left
  1.0f,  0.0f, 0.0f,//top right
  0.0f, 1.0f,  0.0f,//bottom left
  1.0f,  1.0f,  0.0f//bottom right
  };
  GLfloat blueColor[] = {
    0.0f, 1.0f, 0.0f
  };
  GLuint rectangleIndices[] = {
    0, 1, 2,
    1, 2, 3
  };

  GLuint triangleVbo;
  GLuint triangleVao;
  GLuint rectangleEbo;
  GLuint rectangleVbo;
  GLuint rectangleVao;
  ShaderProgram* glProgram1;
  glm::mat4 projectionMatrix;


  void init(){
    windowWidth =  1000;
    windowHeight = 1000;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    sdlWindow_ = SDL_CreateWindow("Test", 50,50,windowWidth,windowHeight, 
        SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(sdlWindow_);

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();

    if(glewError != GLEW_OK)
    {
      std::cout << "Error initializing GLEW!" << 
        glewGetErrorString(glewError) << std::endl;
    }
    else
    {
      std::cout << "Glew OK" << std::endl;
    }

    glViewport( 0.0f, 0.0f, windowWidth, windowHeight);
    glEnable(GL_DEPTH_TEST);

    //generate vertex array object
    glGenVertexArrays(1, &rectangleVao);

    //generate vertex buffer object 
    glGenBuffers(1, &rectangleVbo);

    //generate element buffer object
    glGenBuffers(1, &rectangleEbo);

    //bind vao, it will then "link" the ebo, vbo and
    //vertex attrib pointer config to the vao!
    glBindVertexArray(rectangleVao);
      //bind ebo and put array of indices in it
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangleEbo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices),
          rectangleIndices, GL_STATIC_DRAW);

      //bind vbo and put rectangle vertices in it
      glBindBuffer(GL_ARRAY_BUFFER, rectangleVbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices, GL_STATIC_DRAW); 

      //tell OpenGL how to interpret the vertex data
      //in the currently bound vao
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
        (GLvoid*)0);
      //enable vertex attribute (disabled by default)
      glEnableVertexAttribArray(0);

    //unbind vao
    glBindVertexArray(0);


    //create shaders and a shader program with them
    Shader shadertest = Shader(GL_VERTEX_SHADER, "shader/vertex_shader.gl");
    Shader shadertest2 = Shader(GL_FRAGMENT_SHADER, "shader/fragment_shader.gl");
    glProgram1 = new ShaderProgram(shadertest, shadertest2);
    glProgram1->use();


    projectionMatrix = glm::ortho(0.0f, (float)windowWidth, 
        (float)windowHeight, 0.0f, -1.0f, 1.0f);
  }


  void render(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //drawRectangle(glm::vec2(150.0f,0.0f), glm::vec2(windowWidth,300.0f),
        //glm::vec3(143,54,0));

    auto worldEntities = World::getEntities();
    for (int i = 0 ; i < worldEntities.size() ; ++i){
      drawRectangle(worldEntities[i]->getPosition(), worldEntities[i]->getSize(),
          worldEntities[i]->getColor());
    }
    auto players = World::getPlayers();
    for (int i = 0 ; i < players.size() ; ++i){
      drawRectangle(players[i]->getPosition(), players[i]->getSize(),
          players[i]->getColor());
    }
    auto worldWalls = World::getWalls();
    for (int i = 0 ; i < worldWalls.size() ; ++i){
      if(worldWalls[i] != nullptr){
        drawRectangle(worldWalls[i]->getPosition(), worldWalls[i]->getSize(),
            worldWalls[i]->getColor());
      }
    }
    SDL_GL_SwapWindow(sdlWindow_);
  }

  float zoom = 1.0f;

  void drawRectangle(glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));
    GLuint transformLoc = glGetUniformLocation(glProgram1->getId(), "model");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

    GLuint projectionLoc = glGetUniformLocation(glProgram1->getId(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    color /= 255;
    GLuint colorLoc = glGetUniformLocation(glProgram1->getId(), "inColor");
    glUniform3fv(colorLoc, 1, glm::value_ptr(color));
    glBindVertexArray(rectangleVao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }
  SDL_Window* getWindow(){
    return sdlWindow_; 
  }

  SDL_Renderer* getRenderer(){
    return sdlRenderer_; 
  }

  int getWindowWidth(){
    return windowWidth;
  }
  int getWindowHeight(){
    return windowHeight;
  }
}
