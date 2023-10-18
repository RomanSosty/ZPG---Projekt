#include <iostream>
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

class Shader
{
public:
    void setFragmentShader(const char *fragment_shader_src);
    void setVertexShader(const char *vertex_shader_src);
    const char *getFragmetShader();
    const char *getVertexShader();

private:
    const char *fragment_shader_src;
    const char *vertex_shader_src;
};