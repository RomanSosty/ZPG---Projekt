
#include "../include/Scene.h"
#include "../include/sphere.h"

Scene::Scene()
{
    if (!initWindow())
    {
        printf("Nepovedlo se inicializovat scénu");
        return;
    }
    initShader();
    initGeometry();
    run();
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
    // musíme říct co chceme používat
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

void Scene::initShader()
{
    shaderProgram.createShaders();
    shaderProgram.setId();
    shaderProgram.setShaders();
};

void Scene::initGeometry()
{
    int pointsNumber = sizeof(sphere) / sizeof(sphere[0]);
    drawableObject.initModel(sphere, pointsNumber);
}

void Scene::run()
{
    GLfloat angle;

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        drawableObject.initDrawableObject(shaderProgram);
        initLight();
        drawableObject.getTransformation().transform(shaderProgram.getId(), glm::vec3(0.0f, 0.0f, -2.f), angle);
        drawableObject.draw();

        drawableObject.initDrawableObject(shaderProgram);
        initLight();
        drawableObject.getTransformation().transform(shaderProgram.getId(), glm::vec3(0.0f, 0.0f, 2.f), 0);
        drawableObject.draw();

        drawableObject.initDrawableObject(shaderProgram);
        initLight();
        drawableObject.getTransformation().transform(shaderProgram.getId(), glm::vec3(0.0f, 2.0f, 0.f), 0);
        drawableObject.draw();

        drawableObject.initDrawableObject(shaderProgram);
        initLight();
        drawableObject.getTransformation().transform(shaderProgram.getId(), glm::vec3(0.0f, -2.0f, 0.f), 0);
        drawableObject.draw();

        angle += 0.1f;
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
};

void Scene::initLight()
{

    // Získání umístění uniformních proměnných
    int lightPosLoc = glGetUniformLocation(shaderProgram.getId(), "lightPos");
    int lightColorLoc = glGetUniformLocation(shaderProgram.getId(), "lightColor");
    int objectColorLoc = glGetUniformLocation(shaderProgram.getId(), "objectColor");
    int shininessLoc = glGetUniformLocation(shaderProgram.getId(), "shininess");
    int viewPosLoc = glGetUniformLocation(shaderProgram.getId(), "viewPos");

    // Nastavení hodnot uniformních proměnných
    glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 objectColor = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 cameraPos = glm::vec3(5.0f, 0.0f, 0.f);
    float shininessValue = 32.0f;

    glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));
    glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
    glUniform3fv(objectColorLoc, 1, glm::value_ptr(objectColor));
    glUniform1f(shininessLoc, shininessValue);
    glUniform3fv(viewPosLoc, 1, glm::value_ptr(cameraPos));
}

void Scene::clean()
{
    glBindVertexArray(0);
    glDeleteProgram(shaderProgram.getId());
    glfwDestroyWindow(window);
    glfwTerminate();
}
