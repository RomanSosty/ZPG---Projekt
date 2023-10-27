#include "../include/DrawableObject.h"

void DrawableObject::initDrawableObject(ShaderProgram shaderProgram)
{
    this->shaderProgram = shaderProgram;
    glUseProgram(shaderProgram.getId());
    glBindVertexArray(model.getVao());
}

void DrawableObject::draw()
{
    glDrawArrays(GL_TRIANGLES, 0, 2880);
}

void DrawableObject::initModel(const float points[], int pointsNumber)
{
    model.initModel(points, pointsNumber);
}

Transformation DrawableObject::getTransformation()
{
    return transformation;
}
