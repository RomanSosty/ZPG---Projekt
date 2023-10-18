#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "../include/ShaderProgram.h"
#include "../include/DrawableObject.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

static const char *fragment_shader_src1 =
    "#version 330\n"
    "in vec3 fragColor;"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (fragColor, 1.0);"
    "}";

static const char *vertex_shader_src1 =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "out vec3 fragColor;"
    "uniform mat4 model;"
    "void main () {"
    "     gl_Position = model * vec4(vp, 1.0);"
    "     fragColor = vp;"
    "}";

static const char *fragment_shader_src2 =
    "#version 330\n"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (1.0, 1.0, 0.2, 1.0);"
    "}";

static const char *vertex_shader_src2 =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "uniform mat4 model;"
    "void main () {"
    "     gl_Position = model * vec4(vp, 1.0);"
    "}";

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

#endif