#include "../include/Application.h"
#include "../include/sphere.h"
#include "../include/suzi_smooth.h"
#include "../include/tree.h"

Application::Application()
{
    Scene scene = createScene();

    GLuint id = glCreateProgram();
    scene.createShaderProgram(id);

    ShaderProgram firstShaderProgram = scene.getShaderProgram(id);

    DrawableObject firstBall = scene.createDrawableObject();
    DrawableObject secondBall = scene.createDrawableObject();
    DrawableObject thirdball = scene.createDrawableObject();
    DrawableObject fourthBall = scene.createDrawableObject();

    DrawableObject suziObject = scene.createDrawableObject();
    DrawableObject treeObject = scene.createDrawableObject();

    int pointsCount = sizeof(sphere) / sizeof(float);
    int suziCount = sizeof(suziSmooth) / sizeof(float);
    int treeCount = sizeof(tree) / sizeof(float);

    Model ball = firstBall.createModel(sphere, pointsCount);
    Model suzi = firstBall.createModel(suziSmooth, suziCount);
    Model treeModel = firstBall.createModel(tree, treeCount);

    Transformation transformation = firstBall.createTransformation();
    transformation.setVector(glm::vec3(-2.0f, 0.0f, 0.f));
    Transformation secondTransformation = secondBall.createTransformation();
    secondTransformation.setVector(glm::vec3(2.0f, 0.0f, 0.f));
    Transformation thirdTransformation = thirdball.createTransformation();
    thirdTransformation.setVector(glm::vec3(0.0f, -2.0f, 0.f));
    Transformation fourthTransformation = fourthBall.createTransformation();
    fourthTransformation.setVector(glm::vec3(0.0f, 2.0f, 0.f));

    Transformation suziTransform = suziObject.createTransformation();
    suziTransform.setVector(glm::vec3(10.0f, 0.0f, 0.f));

    Transformation treeTransform = treeObject.createTransformation();
    treeTransform.setVector(glm::vec3(8.0f, 0.0f, 0.f));

    firstBall.initDrawableObject(firstShaderProgram, ball, transformation, 0);
    secondBall.initDrawableObject(firstShaderProgram, ball, secondTransformation, 0);
    thirdball.initDrawableObject(firstShaderProgram, ball, thirdTransformation, 0);
    fourthBall.initDrawableObject(firstShaderProgram, ball, fourthTransformation, 0);
    suziObject.initDrawableObject(firstShaderProgram, suzi, suziTransform, 0);
    treeObject.initDrawableObject(firstShaderProgram, treeModel, treeTransform, 0);

    scene.addDrawableObject(firstBall);
    scene.addDrawableObject(secondBall);
    scene.addDrawableObject(thirdball);
    scene.addDrawableObject(fourthBall);
    // scene.addDrawableObject(suziObject);
    scene.addDrawableObject(treeObject);

    scene.run();

    cleanApp(scene, firstShaderProgram);
}

Scene Application::createScene()
{
    Scene *instance = new Scene();
    return *instance;
}

void Application::cleanApp(Scene scene, ShaderProgram shaderProgram)
{
    scene.clean(shaderProgram);
}
