#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "../include/ShaderProgram.h"
#include "../include/DrawableObject.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include <map>

class Scene
{
public:
    Scene();
    void createShaderProgram(GLuint id);
    ShaderProgram getShaderProgram(GLuint id);
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
    std::map<GLuint, ShaderProgram *> mapShaderProgram;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 9.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    GLint viewLoc;
    glm::mat4 view;

    float cameraSpeed = 0.05f;
};

#endif