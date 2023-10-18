#include "../include/Shader.h"

const char *Shader::getFragmetShader()
{
    return this->fragment_shader_src;
}

const char *Shader::getVertexShader()
{
    return this->vertex_shader_src;
}

void Shader::setFragmentShader(const char *fragment_shader_src)
{
    this->fragment_shader_src = fragment_shader_src;
}

void Shader::setVertexShader(const char *vertex_shader_src)
{
    this->vertex_shader_src = vertex_shader_src;
}
