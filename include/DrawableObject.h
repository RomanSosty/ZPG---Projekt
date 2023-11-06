#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "../include/Model.h"
#include "../include/Transformation.h"
#include "../include/ShaderProgram.h"

class DrawableObject
{
public:
    void initDrawableObject(ShaderProgram shaderProgram, Model model);
    void draw(int pointsCount);
    Model createModel();
    Transformation getTransformation();
    ShaderProgram getShaderProgram();
    Model getModel();

private:
    Transformation transformation;
    ShaderProgram shaderProgram;
    Model model;
};
#endif