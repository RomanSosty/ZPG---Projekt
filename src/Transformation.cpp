#include "../include/Transformation.h"

Transformation::Transformation(glm::vec3 position, glm::vec3 rotation)
{
    this->position = position;
    this->rotation = rotation;
}

glm::mat4 Transformation::getModelMatrix()
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    if (rotation == glm::vec3(0.0f, 1.0f, 0.f))

    {
        modelMatrix = glm::rotate(modelMatrix, this->angle, rotation);
        printf("%f\n", angle);
    }
    this->M = modelMatrix;
    return this->M;
}

void Transformation::updateAngle()
{
    this->angle += 0.01;
}
