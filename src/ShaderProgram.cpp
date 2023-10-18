#include "../include/ShaderProgram.h"

void ShaderProgram::setShader(const char *fragment_shader_src, const char *vertex_shader_src)
{
    Shader shader;
    GLuint vertexShader = shader.createShader(GL_VERTEX_SHADER, vertex_shader_src);
    GLuint fragmentShader = shader.createShader(GL_FRAGMENT_SHADER, fragment_shader_src);

    glAttachShader(this->id, vertexShader);
    glAttachShader(this->id, fragmentShader);
    glLinkProgram(this->id);
}

GLuint ShaderProgram::getId()
{
    return this->id;
}

void ShaderProgram::setId()
{
    this->id = glCreateProgram();
}
