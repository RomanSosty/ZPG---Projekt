#include "../include/Application.h"
#include "../include/sphere.h"

int main()
{
    Application app;
    Scene firstScene = app.createScene();

    ShaderProgram firstShaderProgram = firstScene.createShaderProgram();
    firstShaderProgram.createShaders();
    firstShaderProgram.setId();
    firstShaderProgram.setShaders();

    DrawableObject drawableObject = firstScene.createDrawableObject();

    Model ball = drawableObject.createModel();
    int pointsCount = sizeof(sphere) / sizeof(float);
    ball.initModel(sphere, pointsCount);

    drawableObject.initDrawableObject(firstShaderProgram, ball);

    firstScene.addDrawableObject(drawableObject);
    firstScene.run();

    app.cleanApp(firstScene, firstShaderProgram);
    return 0;
}
