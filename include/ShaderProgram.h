#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../include/Shader.h"

class ShaderProgram
{
public:
    void setShader(const char *fragment_shader_src, const char *vertex_shader_src);
    GLuint getId();
    void setId();

private:
    GLuint id;
};
#endif