#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "../include/Model.h"
#include "../include/Transformation.h"
#include <map>

class DrawableObject
{
public:
    DrawableObject(){};
    ~DrawableObject(){};
    DrawableObject(GLuint shaderProgram, Model model, Transformation transformation, GLfloat angle, glm::vec3 objectColor);

    void setObjectColor();

    GLuint getShaderProgram();
    GLfloat getAngle();
    Model getModel();

    Transformation getTransformation();

private:
    Transformation transformation;
    Model model;

    GLuint shaderProgram;
    GLfloat angle;

    glm::vec3 objectColor;
};
#endif