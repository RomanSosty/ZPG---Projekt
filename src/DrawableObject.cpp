#include "../include/DrawableObject.h"

void DrawableObject::initDrawableObject(GLuint shaderProgram, glm::mat4 model)
{
    this->shaderProgram = shaderProgram;
    this->model = model;
}

void DrawableObject::render()
{
    glBindVertexArray(modelClass.getVao());
    GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
};

void DrawableObject::initModel(GLfloat points[], GLuint indices[], int numPoints, int numIndices)
{
    modelClass.initModel(points, indices, numPoints, numIndices);
}

void DrawableObject::translate(glm::vec3 translationVector)
{
    this->model = transformation.translate(this->model, translationVector);
}

void DrawableObject::rotate(GLfloat angle, glm::vec3 translationVector)
{
    this->model = transformation.rotate(this->model, angle, translationVector);
}

glm::mat4 DrawableObject::getModel()
{
    return this->model;
}