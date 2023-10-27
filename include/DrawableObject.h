#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "../include/Model.h"
#include "../include/Transformation.h"
#include "../include/ShaderProgram.h"

class DrawableObject
{
public:
    void initDrawableObject(ShaderProgram shaderProgram);
    void draw();
    void initModel(const float sphere[], int pointsNumber);
    Transformation getTransformation();

private:
    Model model;
    Transformation transformation;
    ShaderProgram shaderProgram;
};
#endif