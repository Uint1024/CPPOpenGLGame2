#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "SDL.h"
#include <SOIL.h>

#include <GL/glew.h>
#include <SDL_opengl.h>
#include "graphics/renderer.h"
#include "graphics/shader.h"
#include "graphics/shaderProgram.h"
#include "entity.h"
#include "world.h"
#include "player.h"
#include "graphics/sprite.h"

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
  0.0f, 0.0f, 0.0f,   0.0f, 1.0f,//top left
  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,//top right
  0.0f, 1.0f, 0.0f,   0.0f, 0.0f,//bottom left
  1.0f, 1.0f, 0.0f,   1.0f, 0.0f//bottom right
  };

  GLfloat spritePositionArray[] = {
  0.0f, 1.0f,
  0.25f, 1.0f,
  0.0f, 0.75f,
  0.25f, 0.75f
  };

  GLfloat spriteCoordinates[nbTextures][8]; 
  GLfloat someArray[] = {
    0.0f, 1.0f,
    0.25f, 1.0f,
    0.0f, 0.75f,
    0.25f, 0.75f
  };

  GLfloat blueColor[] = {
    0.0f, 1.0f, 0.0f
  };
  GLuint rectangleIndices[] = {
    0, 1, 2,
    1, 2, 3
  };

  std::array<GLuint, nbTextures> spriteVboMap;
  GLuint triangleVbo;
  GLuint triangleVao;
  GLuint rectangleEbo;
  GLuint rectangleVbo;
  GLuint spritePositionVbo;
  GLuint rectangleVao;
  ShaderProgram* glProgram1;
  glm::mat4 projectionMatrix;
  glm::mat4 viewMatrix;
  glm::vec2 cameraPosition;
  int cameraPositionX;
  int cameraPositionY;
  GLuint texture;
  std::vector<std::string> textureNames;


  std::map<std::string, glm::vec2> spritePosition;
  std::map<std::string, glm::vec2> spriteSize;

  void init(){
    cameraPositionX = 0;
    cameraPositionY = 0;

    windowWidth =  1000;
    windowHeight = 1000;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    sdlWindow_ = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth,windowHeight, 
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
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //create shaders and a shader program with them
    Shader shadertest = Shader(GL_VERTEX_SHADER, "shader/vertex_shader.gl");
    
    Shader shadertest2 = Shader(GL_FRAGMENT_SHADER, "shader/fragment_shader.gl");
    glProgram1 = new ShaderProgram(shadertest, shadertest2);
    glProgram1->use();

    //TEXTURE / SPRITE SHEET
    int width, height;
    unsigned char* image  = SOIL_load_image("graphics/spriteSheet.png",
        &width,
        &height,
        0,
        SOIL_LOAD_RGBA);

    //setup of each sprite's position in the spritesheet
    //chaque texture fait 128x128
    float texSize = 128.0f;
    float left = 0.0f;
    float top = 0.0f;
    for (int i = 0 ; i < nbTextures ; ++i){
      float right = left + texSize;
      float bottom = top + texSize;
      //top left
      spriteCoordinates[i][0] = left / width;
      spriteCoordinates[i][1] = 1.0f - top / height;
      //top right
      spriteCoordinates[i][2] = right / width;
      spriteCoordinates[i][3] = spriteCoordinates[i][1];
      //bottom left
      spriteCoordinates[i][4] = spriteCoordinates[i][0];
      spriteCoordinates[i][5] = 1.0f - bottom / height;
      //bottom right
      spriteCoordinates[i][6] = spriteCoordinates[i][2];
      spriteCoordinates[i][7] = spriteCoordinates[i][5];

      left += 128.0f;
      //TODO: set left to 0.0f and y to +texSize when change line in spritesheet
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);

    //VAO / VBO / VEO
    //generate vertex array object
    glGenVertexArrays(1, &rectangleVao);

    //generate vertex buffer object 
    glGenBuffers(1, &rectangleVbo);
    glGenBuffers(1, &spritePositionVbo);

    //generate element buffer object
    glGenBuffers(1, &rectangleEbo);
    
    //bind vao, it will then "link" the ebo, vbo and
    //vertex attrib pointer config to the vao!
    glBindVertexArray(rectangleVao);
      //bind ebo and put array of indices in it
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangleEbo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices),
          rectangleIndices, GL_STATIC_DRAW);

      glBindBuffer(GL_ARRAY_BUFFER, rectangleVbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices),
          rectangleVertices, GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
          (GLvoid*)0);

      glEnableVertexAttribArray(0);

      
      //generate the vbo for every texture
      for(int name = 0 ; name < nbTextures ; ++name){
        glGenBuffers(1, &spriteVboMap[name]);
        glBindBuffer(GL_ARRAY_BUFFER, spriteVboMap[name]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(spriteCoordinates[name]), spriteCoordinates[name], GL_STATIC_DRAW); 
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat),
          (GLvoid*)(0));
        glEnableVertexAttribArray(1);
      }

    //unbind vao
    glBindVertexArray(0);


    projectionMatrix = glm::ortho(0.0f, (float)windowWidth, 
        (float)windowHeight, 0.0f, -1.0f, 1.0f);

    viewMatrix = glm::translate(viewMatrix, 
        glm::vec3(windowWidth/2, windowHeight/2,
        0.0f));
  }


  void render(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    auto players = World::getPlayers();
    viewMatrix = glm::mat4();
    cameraPositionX = players[0]->getPosition().x
      + players[0]->getSize().x / 2;
    cameraPositionY = players[0]->getPosition().y 
      + players[0]->getSize().y / 2;
    viewMatrix = glm::translate(viewMatrix, 
        glm::vec3(windowWidth/2 - cameraPositionX,
        windowHeight/2 - cameraPositionY,
        0.0f));
    auto backgroundMap = World::getBackground();
    for (int i = 0 ; i < backgroundMap.size() ; ++i){
      if(backgroundMap[i] != nullptr){
        drawSprite(backgroundMap[i]->getPosition(), backgroundMap[i]->getSize(),
            backgroundMap[i]->getColor(), backgroundMap[i]->getSpriteName());
      }
    }
    auto worldWalls = World::getWallsVector();
    for (int i = 0 ; i < worldWalls.size() ; ++i){
      if(worldWalls[i] != nullptr){
        drawSprite(worldWalls[i]->getPosition(), worldWalls[i]->getSize(),
            worldWalls[i]->getColor(), worldWalls[i]->getSpriteName());
      }
    }
    auto monsters = World::getNpcsVector();
    for (int i = 0 ; i < monsters.size() ; ++i){
      drawSprite(monsters[i]->getPosition(), monsters[i]->getSize(),
          monsters[i]->getColor(), monsters[i]->getSpriteName());
    }
    auto bullets = World::getBulletsVector();
    for (int i = 0 ; i < bullets.size() ; ++i){
      drawSprite(bullets[i]->getPosition(), bullets[i]->getSize(),
          bullets[i]->getColor(), bullets[i]->getSpriteName());
    }
    for (int i = 0 ; i < players.size() ; ++i){
      drawSprite(players[i]->getPosition(), players[i]->getSize(),
          players[i]->getColor(), players[i]->getSpriteName());
    }

    SDL_GL_SwapWindow(sdlWindow_);
  }

  void drawSprite(glm::vec2 position, glm::vec2 size, glm::vec3 color,
      int spriteName) {
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));
    GLuint transformLoc = glGetUniformLocation(glProgram1->getId(), "model");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

    GLuint projectionLoc = glGetUniformLocation(glProgram1->getId(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    GLuint viewLoc = glGetUniformLocation(glProgram1->getId(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    color /= 255;
    GLuint colorLoc = glGetUniformLocation(glProgram1->getId(), "inColor");
    glUniform3fv(colorLoc, 1, glm::value_ptr(color));
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(rectangleVao);
    glBindBuffer(GL_ARRAY_BUFFER, spriteVboMap[spriteName]);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat),
        (GLvoid*)(0));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }

  void drawRectangle(glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    rectangleVertices[0] = 1.0f;
    glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices, GL_STATIC_DRAW); 
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
    glBindTexture(GL_TEXTURE_2D, texture);
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

  int getCameraY(){
    return cameraPositionY;
  }

  int getCameraX(){
    return cameraPositionX;
  }

  
}

