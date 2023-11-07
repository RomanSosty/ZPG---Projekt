#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <map>
#include "../include/DrawableObject.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include "../include/Camera.h"

class Scene
{
public:
    Scene();
    ~Scene(){};

    void run();
    void clean();
    void addDrawableObject(DrawableObject drawableObject);

private:
    bool initWindow();
    void initLight(GLuint shaderProgram);
    void addObserver(Camera *camera);
    void updateCameras();

    GLFWwindow *window;
    int width, height;

    std::vector<DrawableObject> drawableObjects;
    std::vector<Camera *> cameras;

    glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 lightSuziPos = glm::vec3(7.0f, 0.0f, 10.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 9.0f);
    float shininessValue = 32.0f;

    GLint matrixID;
    GLint viewMatrixID;
};

#endif