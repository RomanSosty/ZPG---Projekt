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

    glm::vec3 rotate = glm::vec3(0.0f, 1.0f, 0.f);
    glm::vec3 noRotate = glm::vec3(0.0f, 0.0f, 0.f);

    Transformation *firstBallT = new Transformation(glm::vec3(-2.0f, 0.0f, 0.f), noRotate);
    Transformation *secondBallT = new Transformation(glm::vec3(2.0f, 0.0f, 0.f), noRotate);
    Transformation *thirdBallT = new Transformation(glm::vec3(0.0f, -2.0f, 0.f), noRotate);
    Transformation *fourthBallT = new Transformation(glm::vec3(0.0f, 2.0f, 0.f), rotate);

    Transformation *suziTransfom = new Transformation(glm::vec3(7.0f, 0.0f, 0.f), rotate);

    Transformation *firstTreeT = new Transformation(glm::vec3(12.0f, -4.0f, 0.f), noRotate);
    Transformation *secondTreeT = new Transformation(glm::vec3(11.0f, -4.0f, 0.f), noRotate);
    Transformation *thirdTreeT = new Transformation(glm::vec3(11.5f, -4.0f, 0.f), noRotate);
    Transformation *fourthTreeT = new Transformation(glm::vec3(11.7f, -4.0f, 0.f), noRotate);

    DrawableObject firstBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), firstBallT, glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject secondBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), secondBallT, glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject thirdBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), thirdBallT, glm::vec3(0.5f, 0.5f, 1.0f));
    DrawableObject fourthBall = DrawableObject(firstShaderProgram, Model(sphere, pointsCount), fourthBallT, glm::vec3(0.5f, 0.5f, 1.0f));

    DrawableObject suziObject = DrawableObject(suziShaderProgram, Model(suziSmooth, suziCount), suziTransfom, glm::vec3(0.8f, 0.5f, 1.0f));

    DrawableObject firstTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), firstTreeT, glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject secondTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), secondTreeT, glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject thirdTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), thirdTreeT, glm::vec3(0.8f, 0.5f, 0.0f));
    DrawableObject fourthTree = DrawableObject(firstShaderProgram, Model(tree, treeCount), fourthTreeT, glm::vec3(0.8f, 0.5f, 0.0f));

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
