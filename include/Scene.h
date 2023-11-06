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

    ShaderProgram createShaderProgram();
    DrawableObject createDrawableObject();

    void run();
    void clean(ShaderProgram shaderProgram);
    void addDrawableObject(DrawableObject drawableObject);

private:
    bool initWindow();
    void initLight(ShaderProgram shaderProgram);

    GLFWwindow *window;
    int width, height;

    std::vector<DrawableObject> drawableObjects;
};

#endif