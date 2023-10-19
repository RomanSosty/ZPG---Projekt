#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "../include/Model.h"
#include "../include/Transformation.h"

class DrawableObject
{
public:
    void initDrawableObject(GLuint shaderProgram, glm::mat4 model);
    void initModel(GLfloat points[], GLuint indices[], int numPoints, int numIndices);
    void translate(glm::vec3 translationVector);
    void rotate(GLfloat angle, glm::vec3 translationVector);
    void render(glm::mat4 view, glm::mat4 projection);
    glm::mat4 getModel();

private:
    GLuint shaderProgram;
    Model modelClass;
    Transformation transformation;
    glm::mat4 model;
};
#endif