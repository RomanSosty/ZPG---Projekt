#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "../include/Model.h"
#include "../include/Transformation.h"
#include "../include/ShaderProgram.h"
#include <map>

class DrawableObject
{
public:
    DrawableObject(){};
    ShaderProgram getShaderProgram();
    void initDrawableObject(ShaderProgram shaderProgram, Model model, Transformation transformation, GLfloat angle);
    void draw(int pointsCount);

    Model createModel(float *points, int pointsCount);
    Model getModel();

    Transformation createTransformation();
    Transformation getTransformation();

    GLfloat getAngle();

private:
    Transformation transformation;
    Model model;
    ShaderProgram shaderProgram;

    GLfloat angle;
    std::map<GLuint, ShaderProgram *> mapShaderProgram;
};
#endif