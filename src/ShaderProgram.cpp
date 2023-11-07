#include "../include/ShaderProgram.h"

ShaderProgram::ShaderProgram(GLuint id)
{
    this->id = id;
    createShaders();
    setShaders();
}

void ShaderProgram::setShaders()
{
    glAttachShader(this->id, vertexShader);
    glAttachShader(this->id, fragmentShader);
    glLinkProgram(this->id);
}

void ShaderProgram::createShaders()
{
    Shader shader;
    vertexShader = shader.createVertexShader();
    fragmentShader = shader.createFragmentShader();
}

GLuint ShaderProgram::getId()
{
    return this->id;
}
