#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

static const char *fragment_shader_src =
    "#version 330\n"
    "in vec3 FragPos;"
    "in vec3 Normal;"
    "out vec4 frag_color;"
    "uniform vec3 lightPos;"
    "uniform vec3 lightColor;"
    "uniform vec3 objectColor;"
    "uniform vec3 viewPos;"
    "uniform float shininess;"
    "void main () {"
    "     vec3 ambient = 0.1 * objectColor;" // ambientní složka osvětlení
    "     vec3 lightDir = normalize(lightPos - FragPos);"
    "     float diff = max(dot(Normal, lightDir),0.0);"
    "     vec3 diffuse = diff * lightColor * objectColor;" // difúzní složka
    "     vec3 viewDir = normalize(viewPos - FragPos);"
    "     vec3 reflectDir = reflect(-lightDir, Normal);"
    "     float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);"
    "     vec3 specular = spec * lightColor;" // spekulární složka osvětlení
    "     vec3 result = (ambient + diffuse + specular);"
    "     frag_color = vec4(result, 1.0);"
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