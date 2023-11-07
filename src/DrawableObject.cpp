#include "../include/DrawableObject.h"

DrawableObject::DrawableObject(GLuint shaderProgram, Model model, Transformation transformation, glm::vec3 objectColor)
{
    this->shaderProgram = shaderProgram;
    this->transformation = transformation;
    this->model = model;
    this->objectColor = objectColor;
}

Model DrawableObject::getModel()
{
    return this->model;
}

Transformation DrawableObject::getTransformation()
{
    return this->transformation;
}

GLuint DrawableObject::getShaderProgram()
{
    return this->shaderProgram;
};

void DrawableObject::initObjectColor()
{
    int objectColorLoc = glGetUniformLocation(getShaderProgram(), "objectColor");
    glUniform3fv(objectColorLoc, 1, glm::value_ptr(this->objectColor));
}
