#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "../include/ShaderProgram.h"
#include "../include/DrawableObject.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

class Scene
{
public:
    Scene();
    void clean();

private:
    void run();
    bool initWindow();
    void initShader();
    void initGeometry();

    GLFWwindow *window;
    ShaderProgram shaderProgram;

    DrawableObject drawableObject;
    int width, height;
};

#endif