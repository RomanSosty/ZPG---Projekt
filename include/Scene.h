#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "../include/DrawableObject.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include <map>

class Scene
{
public:
    Scene();

    void run();
    void clean();
    void addDrawableObject(DrawableObject drawableObject);
    void cameraMove();

private:
    bool initWindow();
    void initLight(GLuint shaderProgram);

    GLFWwindow *window;
    int width, height;

    std::vector<DrawableObject> drawableObjects;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 9.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 lightSuziPos = glm::vec3(7.0f, 0.0f, 1.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    float shininessValue = 32.0f;

    GLint matrixID;

    float cameraSpeed = 0.05f;
};

#endif