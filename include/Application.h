#ifndef APPLICATION_H
#define APPLICATION_H

#include "../include/Scene.h"

class Application
{
public:
    Scene createScene();
    void cleanApp(Scene scene, ShaderProgram shaderProgram);
};

#endif