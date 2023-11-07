#include "../include/Application.h"

int main()
{
    Application *app = new Application();

    app->createShaders();
    app->createModels();
    app->run();
    app->cleanApp();

    return 0;
}
