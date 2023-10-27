#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

static const char *fragment_shader_src =
    "#version 330\n"
    "in vec3 fragColor;"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (fragColor, 0.0);"
    "}";

static const char *vertex_shader_src =
    "#version 330\n"
    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 project;"
    "layout(location=0) in vec3 vp;"
    "layout(location=1) in vec3 vn;"
    "out vec3 fragColor;"
    "void main () {"
    "     gl_Position = project * view * model * vec4(vp, 1.0);"
    "     fragColor = vp;"
    "}";

class Shader
{
public:
    GLuint createVertexShader();
    GLuint createFragmentShader();
};

#endif