#include "../include/Model.h"

void Model::initModel(float *points, int pointsCount)
{
    this->pointsCount = pointsCount;
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * pointsCount, points, GL_STATIC_DRAW);

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
}

GLuint Model::getVao()
{
    return this->vao;
}

GLuint Model::getVbo()
{
    return this->vbo;
}

int Model::getPointsCount()
{
    return this->pointsCount;
}