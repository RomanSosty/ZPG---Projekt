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
    void initModel(GLfloat points[], GLuint indices[], int numPoints, int numIndices);
    GLuint getVao();
    GLuint getVbo();

private:
    GLuint vao, vbo, ebo;
};