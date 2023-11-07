#include "../include/DrawableObject.h"

DrawableObject::DrawableObject(GLuint shaderProgram, Model model, glm::vec3 transformation, GLfloat angle, glm::vec3 objectColor)
{
    this->shaderProgram = shaderProgram;
    this->transformation = transformation;
    this->model = model;
    this->angle = angle;
    this->objectColor = objectColor;
}

void DrawableObject::draw(int pointsCount)
{
    glDrawArrays(GL_TRIANGLES, 0, pointsCount);
}

Model DrawableObject::getModel()
{
    return this->model;
}

glm::vec3 DrawableObject::getTransformation()
{
    return this->transformation;
}

GLuint DrawableObject::getShaderProgram()
{
    return this->shaderProgram;
};

GLfloat DrawableObject::getAngle()
{
    return this->angle;
}

glm::vec3 DrawableObject::getColor()
{
    return this->objectColor;
}
