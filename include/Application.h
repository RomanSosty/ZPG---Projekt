#ifndef APPLICATION_H
#define APPLICATION_H

#include "../include/Scene.h"

class Application
{
public:
    Application();
    Scene createScene();
    void cleanApp(Scene scene, ShaderProgram shaderProgram);
};

#endif