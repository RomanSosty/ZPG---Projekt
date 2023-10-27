#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

static const char *fragment_shader_src =
    "#version 330\n"
    "in vec3 FragPos;"
    "in vec3 Normal;"
    "out vec4 frag_colour;"
    "uniform vec3 lightPos;"
    "uniform vec3 lightColor;"
    "uniform vec3 objectColor;"
    "void main () {"
    "     vec3 lightDir = normalize(lightPos - FragPos);"
    "     vec3 ambient = 0.1 * objectColor;"
    "     float diff = max(dot(Normal, lightDir),0.0);"
    "     vec3 diffuse = diff * lightColor * objectColor;"
    "     frag_colour = vec4(ambient + diffuse, 1.0);"
    "}";

static const char *vertex_shader_src =
    "#version 330\n"
    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 project;"
    "layout(location=0) in vec3 vp;"
    "layout(location=1) in vec3 vn;"
    "out vec3 FragPos;"
    "out vec3 Normal;"
    "void main () {"
    "     FragPos = vec3(model * vec4(vp, 1.0));"
    "     Normal = mat3(transpose(inverse(model))) * vn;"
    "     gl_Position = project * view * model * vec4(vp, 1.0);"
    "}";

class Shader
{
public:
    GLuint createVertexShader();
    GLuint createFragmentShader();
};

#endif