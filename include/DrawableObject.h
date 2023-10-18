#include "../include/Model.h"
#include "../include/Transformation.h"

class DrawableObject
{
public:
    DrawableObject(GLuint shaderProgram, glm::mat4 model);
    void initModel(GLfloat points[], GLuint indices[], int numPoints, int numIndices);
    void transform(const glm::mat4 &newModel);
    void render();
    glm::mat4 getModel();

private:
    GLuint shaderProgram;
    Model modelClass;
    Transformation transformation;
    glm::mat4 model;
};