#include "../include/Application.h"
#include "../include/models/sphere.h"
#include "../include/models/suzi_smooth.h"
#include "../include/models/tree.h"

void Application::createShaders()
{
    shaderLoader = ShaderLoader();
    firstShaderProgram = shaderLoader.loadShader("../include/shaders/vertexShader.glsl", "../include/shaders/fragmentShader.glsl");
    suziShaderProgram = shaderLoader.loadShader("../include/shaders/suziVertexShader.glsl", "../include/shaders/suziFragmentShader.glsl");
}

void Application::createModels()
{
    int pointsCount = sizeof(sphere) / sizeof(float);
    int suziCount = sizeof(suziSmooth) / sizeof(float);
    int treeCount = sizeof(tree) / sizeof(float);

    DrawableObject firstBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), Transformation(glm::vec3(-2.0f, 0.0f, 0.f)), glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject secondBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), Transformation(glm::vec3(2.0f, 0.0f, 0.f)), glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject thirdBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), Transformation(glm::vec3(0.0f, -2.0f, 0.f)), glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject fourthBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), Transformation(glm::vec3(0.0f, 2.0f, 0.f)), glm::vec3(0.5f, 0.5f, 1.0f));

    DrawableObject suziObject = DrawableObject(suziShaderProgram, Model(suziSmooth, suziCount), Transformation(glm::vec3(7.0f, 0.0f, 0.f)), glm::vec3(0.8f, 0.5f, 1.0f));

    DrawableObject firstTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), Transformation(glm::vec3(12.0f, -4.0f, 0.f)), glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject secondTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), Transformation(glm::vec3(11.0f, -4.0f, 0.f)), glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject thirdTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), Transformation(glm::vec3(11.5f, -4.0f, 0.f)), glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject fourthTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), Transformation(glm::vec3(11.7f, -4.0f, 0.f)), glm::vec3(0.8f, 0.5f, 0.0f));

    scene.addDrawableObject(suziObject);

    scene.addDrawableObject(firstBall);
    scene.addDrawableObject(secondBall);
    scene.addDrawableObject(thirdBall);
    scene.addDrawableObject(fourthBall);

    scene.addDrawableObject(firstTree);
    scene.addDrawableObject(secondTree);
    scene.addDrawableObject(thirdTree);
    scene.addDrawableObject(fourthTree);
}

void Application::run()
{
    scene.run();
}

void Application::cleanApp()
{
    shaderLoader.deleteShader();
    scene.clean();
}
