#include "../include/ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
    this->id = glCreateProgram();
}
void ShaderProgram::setShader(const char *fragment_shader_src, const char *vertex_shader_src)
{
    shader.setFragmentShader(fragment_shader_src);
    shader.setVertexShader(vertex_shader_src);
    GLuint vertexShader = createShader(GL_VERTEX_SHADER, shader.getVertexShader());
    GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, shader.getFragmetShader());

    glAttachShader(this->id, vertexShader);
    glAttachShader(this->id, fragmentShader);
    glLinkProgram(this->id);
}

GLuint ShaderProgram::getId()
{
    return this->id;
}

GLuint ShaderProgram::createShader(GLenum shaderType, const char *source)
{
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE)
    {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        char *logInfo = new char[logLength];
        glGetShaderInfoLog(shader, logLength, nullptr, logInfo);
        printf("Shader compilation failed: %s", logInfo);
        delete[] logInfo;
    }
    return shader;
}