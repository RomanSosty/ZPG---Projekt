#include "../include/Application.h"
#include "../include/models/sphere.h"
#include "../include/models/suzi_smooth.h"
#include "../include/models/tree.h"
#include "../include/ShaderLoader.h"

Application::Application()
{
    Scene scene = Scene();

    ShaderLoader shaderLoader = ShaderLoader();
    GLuint firstShaderProgram = shaderLoader.loadShader("../include/shaders/vertexShader.glsl", "../include/shaders/fragmentShader.glsl");
    GLuint suziShaderProgram = shaderLoader.loadShader("../include/shaders/suziVertexShader.glsl", "../include/shaders/suziFragmentShader.glsl");

    int pointsCount = sizeof(sphere) / sizeof(float);
    int suziCount = sizeof(suziSmooth) / sizeof(float);
    int treeCount = sizeof(tree) / sizeof(float);

    Model ball = Model(sphere, pointsCount);
    Model suzi = Model(suziSmooth, suziCount);
    Model treeModel = Model(tree, treeCount);

    DrawableObject firstBall = DrawableObject(firstShaderProgram, ball, glm::vec3(-2.0f, 0.0f, 0.f), 0, glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject secondBall = DrawableObject(firstShaderProgram, ball, glm::vec3(2.0f, 0.0f, 0.f), 0, glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject thirdBall = DrawableObject(firstShaderProgram, ball, glm::vec3(0.0f, -2.0f, 0.f), 0, glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject fourthBall = DrawableObject(firstShaderProgram, ball, glm::vec3(0.0f, 2.0f, 0.f), 0, glm::vec3(0.5f, 0.5f, 1.0f));

    DrawableObject suziObject = DrawableObject(suziShaderProgram, suzi, glm::vec3(7.0f, 0.0f, 0.f), 0, glm::vec3(0.8f, 0.5f, 1.0f));

    DrawableObject firstTree = DrawableObject(firstShaderProgram, treeModel, glm::vec3(12.0f, -4.0f, 0.f), 0, glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject secondTree = DrawableObject(firstShaderProgram, treeModel, glm::vec3(11.0f, -4.0f, 0.f), 0, glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject thirdTree = DrawableObject(firstShaderProgram, treeModel, glm::vec3(11.5f, -4.0f, 0.f), 0, glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject fourthTree = DrawableObject(firstShaderProgram, treeModel, glm::vec3(11.7f, -4.0f, 0.f), 0, glm::vec3(0.8f, 0.5f, 0.0f));

    scene.addDrawableObject(suziObject);

    scene.addDrawableObject(firstBall);
    scene.addDrawableObject(secondBall);
    scene.addDrawableObject(thirdBall);
    scene.addDrawableObject(fourthBall);

    scene.addDrawableObject(firstTree);
    scene.addDrawableObject(secondTree);
    scene.addDrawableObject(thirdTree);
    scene.addDrawableObject(fourthTree);

    scene.run();

    shaderLoader.deleteShader();
    cleanApp(scene);
}

void Application::cleanApp(Scene scene)
{
    scene.clean();
}
