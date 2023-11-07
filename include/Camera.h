#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Camera
{
public:
    Camera(){};
    ~Camera(){};
    void updateViewMatrix();
    void cameraMove(GLFWwindow *window);
    glm::mat4 getViewMatrix();

private:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 9.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float cameraSpeed = 0.05f;
};

#endif