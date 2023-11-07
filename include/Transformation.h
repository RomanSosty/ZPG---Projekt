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
    Transformation(){};
    ~Transformation(){};
    Transformation(glm::vec3 position);
    glm::mat4 getModelMatrix();

private:
    glm::mat4 M;
};

#endif