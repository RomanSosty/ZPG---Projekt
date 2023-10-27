#include "../include/Transformation.h"

void Transformation::transform(GLuint shaderProgram, glm::vec3 translationVector, float angle)
{
    M = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f));
    M = glm::translate(M, translationVector);
    matrixID = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));

    M = glm::lookAt(glm::vec3(5.0f, 0.0f, 0.0f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
    matrixID = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));

    M = glm::perspective(45.0f, 800.f / 600.f, 0.1f, 100.0f);
    matrixID = glGetUniformLocation(shaderProgram, "project");
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));
}