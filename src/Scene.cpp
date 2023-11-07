
#include "../include/Scene.h"

Scene::Scene()
{
    if (!initWindow())
    {
        printf("Nepovedlo se inicializovat scénu");
        return;
    }
};

bool Scene::initWindow()
{
    if (!glfwInit())
    {
        printf("Není inicializace glfw");
        return false;
    };

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "SOS0038", NULL, NULL);

    if (!window)
    {
        printf("Okno se nepodařilo vytvořit");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        printf("Failed to initialize GLEW");
        return false;
    }

    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    return true;
}

void Scene::run()
{
    GLfloat angle;
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (DrawableObject &object : drawableObjects)
        {
            glUseProgram(object.getShaderProgram());

            initLight(object.getShaderProgram());

            glm::mat4 M = glm::mat4(1.0f);
            M = glm::translate(M, object.getTransformation());
            matrixID = glGetUniformLocation(object.getShaderProgram(), "model");
            glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));

            M = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
            matrixID = glGetUniformLocation(object.getShaderProgram(), "view");
            glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));

            M = glm::perspective(45.0f, 800.f / 600.f, 0.1f, 100.0f);
            matrixID = glGetUniformLocation(object.getShaderProgram(), "project");
            glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(M));

            int objectColorLoc = glGetUniformLocation(object.getShaderProgram(), "objectColor");
            glUniform3fv(objectColorLoc, 1, glm::value_ptr(object.getColor()));

            glBindVertexArray(object.getModel().getVao());

            glDrawArrays(GL_TRIANGLES, 0, 5824);
        }

        cameraMove();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
};

void Scene::initLight(GLuint shaderProgram)
{

    // Získání umístění uniformních proměnných
    int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
    int lightSuziPosLoc = glGetUniformLocation(shaderProgram, "lightSuziPos");
    int lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
    int shininessLoc = glGetUniformLocation(shaderProgram, "shininess");
    int viewPosLoc = glGetUniformLocation(shaderProgram, "viewPos");

    glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));
    glUniform3fv(lightSuziPosLoc, 1, glm::value_ptr(lightSuziPos));
    glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
    glUniform1f(shininessLoc, shininessValue);
    glUniform3fv(viewPosLoc, 1, glm::value_ptr(cameraPos));
}

void Scene::addDrawableObject(DrawableObject drawableObject)
{
    drawableObjects.push_back(drawableObject);
}

void Scene::clean()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Scene::cameraMove()
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        cameraPos += cameraSpeed * cameraFront; // Pohyb dopředu
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        cameraPos -= cameraSpeed * cameraFront; // Pohyb zpět
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed; // Pohyb doleva
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed; // Pohyb doprava
    }
}
