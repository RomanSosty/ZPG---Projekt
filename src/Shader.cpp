#include "../include/Shader.h"

GLuint Shader::createShader(GLenum shaderType, const char *source)
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
