#include "../include/Application.h"

Scene Application::createScene()
{
    Scene *instance = new Scene();
    return *instance;
}

void Application::cleanApp(Scene scene, ShaderProgram shaderProgram)
{
    scene.clean(shaderProgram);
}
