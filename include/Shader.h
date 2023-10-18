#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

class Shader
{
public:
    GLuint createShader(GLenum shaderType, const char *source);
};

#endif