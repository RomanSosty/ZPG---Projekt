#include "../include/Transformation.h"

Transformation::Transformation(glm::vec3 position)
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    modelMatrix = glm::translate(modelMatrix, position);
    this->M = modelMatrix;
}

glm::mat4 Transformation::getModelMatrix()
{
    return this->M;
}
