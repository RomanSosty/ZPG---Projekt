#include "../include/Transformation.h"

const glm::mat4 Transformation::translate(glm::mat4 model, glm::vec3 translationVector)
{
    this->model = glm::translate(model, translationVector);
    return this->model;
}

const glm::mat4 Transformation::rotate(glm::mat4 model, GLfloat angle, glm::vec3 translationVector)
{
    this->model = glm::rotate(model, glm::radians(angle), translationVector);
    return this->model;
}