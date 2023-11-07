
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

void Scene::createShaderProgram(GLuint id)
{
    ShaderProgram *shaderProgram = new ShaderProgram(id);
    mapShaderProgram[id] = shaderProgram;
};

ShaderProgram Scene::getShaderProgram(GLuint id)
{
    if (mapShaderProgram.find(id) != mapShaderProgram.end())
    {
        return *mapShaderProgram[id];
    }
    else
    {
        printf("ShaderProgram nenalezen");
        return 0;
    }
};

DrawableObject Scene::createDrawableObject()
{
    DrawableObject *drawableObject = new DrawableObject();
    return *drawableObject;
};

void Scene::run()
{
    GLfloat angle;
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        for (auto &object : drawableObjects)
        {
            Transformation transformation = object.getTransformation();
            glUseProgram(object.getShaderProgram().getId());
            glBindVertexArray(object.getModel().getVao());
            initLight(object.getShaderProgram());

            GLint viewLoc = glGetUniformLocation(object.getShaderProgram().getId(), "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

            transformation.transform(object.getShaderProgram().getId(), transformation.getVector(), object.getAngle());

            object.draw(object.getModel().getPointsCount());
        }

        angle += 0.1f;

        glfwSwapBuffers(window);
    }
};

void Scene::initLight(ShaderProgram shaderProgram)
{

    // Získání umístění uniformních proměnných
    int lightPosLoc = glGetUniformLocation(shaderProgram.getId(), "lightPos");
    int lightColorLoc = glGetUniformLocation(shaderProgram.getId(), "lightColor");
    int objectColorLoc = glGetUniformLocation(shaderProgram.getId(), "objectColor");
    int shininessLoc = glGetUniformLocation(shaderProgram.getId(), "shininess");
    int viewPosLoc = glGetUniformLocation(shaderProgram.getId(), "viewPos");

    // Nastavení hodnot uniformních proměnných
    glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 objectColor = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.f);
    float shininessValue = 32.0f;

    glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));
    glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
    glUniform3fv(objectColorLoc, 1, glm::value_ptr(objectColor));
    glUniform1f(shininessLoc, shininessValue);
    glUniform3fv(viewPosLoc, 1, glm::value_ptr(cameraPos));
}

void Scene::addDrawableObject(DrawableObject drawableObject)
{
    drawableObjects.push_back(drawableObject);
}

void Scene::clean(ShaderProgram shaderProgram)
{
    glBindVertexArray(0);
    glDeleteProgram(shaderProgram.getId());
    glfwDestroyWindow(window);
    glfwTerminate();
}
