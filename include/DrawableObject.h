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
    DrawableObject(GLuint shaderProgram, Model model, Transformation *transformation, glm::vec3 objectColor);

    void initObjectColor();

    GLuint getShaderProgram();
    Model getModel();
    Transformation *getTransformation();

private:
    Transformation *transformation;
    Model model;
    GLuint shaderProgram;
    glm::vec3 objectColor;
};
#endif