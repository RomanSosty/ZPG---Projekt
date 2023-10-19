#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "../include/ShaderProgram.h"
#include "../include/DrawableObject.h"
#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"

static const char *fragment_shader_src =
    "#version 330\n"
    "in vec3 fragColor;"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (fragColor, 1.0);"
    "}";

static const char *vertex_shader_src =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "out vec3 fragColor;"
    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 projection;"
    "void main () {"
    "     gl_Position = projection * view * model * vec4(vp, 1.0);"
    "     fragColor = vp;"
    "}";

static const char *fragment_shader_src2 =
    "#version 330\n"
    "in vec3 fragColor;"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (1.0, 1.0, 0.5, 1.0);"
    "}";

static const char *vertex_shader_src2 =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "out vec3 fragColor;"
    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 projection;"
    "void main () {"
    "     gl_Position = projection * view * model * vec4(vp, 1.0);"
    "     fragColor = vp;"
    "}";

class Scene
{
public:
    Scene();
    void clean();

private:
    void run();
    bool initWindow();
    void initObjects();
    void initGeometry();
    void drawObject(ShaderProgram shaderProgram, DrawableObject object,
                    GLfloat angle, glm::vec3 translationVector);
    void processInput(GLFWwindow *window);

    GLFWwindow *window;
    ShaderProgram shaderProgram1;
    ShaderProgram shaderProgram2;
    glm::mat4 model, model2, view, projection;

    DrawableObject drawableObject1;
    DrawableObject drawableObject2;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float cameraSpeed = 0.05f;
    float cameraYaw = -90.0f;
    float cameraPitch = 0.0f;

    int width, height;
};

#endif