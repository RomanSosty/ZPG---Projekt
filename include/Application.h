#ifndef APPLICATION_H
#define APPLICATION_H

#include "../include/Scene.h"

class Application
{
public:
    Application();
    ~Application(){};
    void cleanApp(Scene scene);
};

#endif