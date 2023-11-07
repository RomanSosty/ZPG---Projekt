#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "../include/Model.h"
#include "../include/Transformation.h"
#include <map>

class DrawableObject
{
public:
    DrawableObject(){};
    DrawableObject(GLuint shaderProgram, Model model, glm::vec3 transformation, GLfloat angle, glm::vec3 objectColor);
    void draw(int pointsCount);
    GLuint getShaderProgram();

    Model getModel();

    glm::vec3 getTransformation();
    glm::vec3 getColor();

    GLfloat getAngle();

private:
    glm::vec3 transformation;
    Model model;
    GLuint shaderProgram;

    GLfloat angle;
    glm::vec3 objectColor;
};
#endif