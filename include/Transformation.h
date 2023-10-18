#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Transformation
{
public:
    const glm::mat4 translate(glm::mat4 model, glm::vec3 translationVector);
    const glm::mat4 rotate(glm::mat4 model, GLfloat angle, glm::vec3 translationVector);

private:
    glm::mat4 model;
};

#endif