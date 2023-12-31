#ifndef MODEL_H
#define MODEL_H

#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Model
{
public:
    Model(){};
    ~Model(){};
    Model(const float *points, int pointsCount);
    GLuint getVao();
    GLuint getVbo();
    int getPointsCount();

private:
    GLuint VAO, VBO = 0;
    int pointsCount;
};

#endif