#include "../include/DrawableObject.h"

void DrawableObject::initDrawableObject(ShaderProgram shaderProgram, Model model, Transformation transformation, GLfloat angle)
{
    this->shaderProgram = shaderProgram;
    this->transformation = transformation;
    this->model = model;
    this->angle = angle;
}

void DrawableObject::draw(int pointsCount)
{
    glDrawArrays(GL_TRIANGLES, 0, pointsCount);
}

Model DrawableObject::createModel(float *points, int pointsCount)
{
    Model model = Model();
    model.initModel(points, pointsCount);
    return model;
}

Model DrawableObject::getModel()
{
    return this->model;
}

Transformation DrawableObject::createTransformation()
{
    Transformation transformation = Transformation();
    return transformation;
}

Transformation DrawableObject::getTransformation()
{
    return this->transformation;
}

ShaderProgram DrawableObject::getShaderProgram()
{
    return this->shaderProgram;
};

GLfloat DrawableObject::getAngle()
{
    return this->angle;
}
