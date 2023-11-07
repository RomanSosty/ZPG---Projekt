#ifndef APPLICATION_H
#define APPLICATION_H

#include "../include/Scene.h"
#include "../include/ShaderLoader.h"

class Application
{
public:
    Application(){};
    ~Application(){};

    void createShaders();
    void createModels();
    void run();
    void cleanApp();

private:
    Scene scene;
    ShaderLoader shaderLoader;
    GLuint firstShaderProgram;
    GLuint suziShaderProgram;
};

#endif