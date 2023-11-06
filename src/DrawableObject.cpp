#include "../include/DrawableObject.h"

void DrawableObject::initDrawableObject(ShaderProgram shaderProgram, Model model)
{
    this->shaderProgram = shaderProgram;
    this->model = model;
    glUseProgram(shaderProgram.getId());
    glBindVertexArray(model.getVao());
}

void DrawableObject::draw(int pointsCount)
{
    glDrawArrays(GL_TRIANGLES, 0, pointsCount);
}

Model DrawableObject::createModel()
{
    Model *model = new Model();
    return *model;
}

Transformation DrawableObject::getTransformation()
{
    return transformation;
}

Model DrawableObject::getModel()
{
    return this->model;
}

ShaderProgram DrawableObject::getShaderProgram()
{
    return this->shaderProgram;
}
