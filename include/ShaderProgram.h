#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../include/Shader.h"

class ShaderProgram
{
public:
    GLuint getId();
    void setShaders();
    void createShaders();
    void setId();

private:
    GLuint id;
    GLuint fragmentShader;
    GLuint vertexShader;
};
#endif