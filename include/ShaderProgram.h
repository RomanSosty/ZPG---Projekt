#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../include/Shader.h"

class ShaderProgram
{
public:
    ShaderProgram(){};
    ShaderProgram(GLuint id);
    GLuint getId();
    void setShaders();
    void createShaders();

private:
    GLuint id;
    GLuint fragmentShader;
    GLuint vertexShader;
};
#endif