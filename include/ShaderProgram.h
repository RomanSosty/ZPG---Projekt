#include "../include/Shader.h"

class ShaderProgram
{
public:
    ShaderProgram();
    void setShader(const char *fragment_shader_src, const char *vertex_shader_src);
    GLuint getId();

private:
    GLuint createShader(GLenum shaderType, const char *source);
    GLuint id;
    Shader shader;
};