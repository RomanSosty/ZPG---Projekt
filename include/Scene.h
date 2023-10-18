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
    void initObjects();
    void initGeometry();

    GLFWwindow *window;
    ShaderProgram shaderProgram1;
    ShaderProgram shaderProgram2;
    glm::mat4 model;
    glm::mat4 model2;
    DrawableObject drawableObject1;
    DrawableObject drawableObject2;
};