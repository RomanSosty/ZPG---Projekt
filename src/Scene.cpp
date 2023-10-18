
#include "../include/Scene.h"

Scene::Scene()
{
    if (!initWindow())
    {
        printf("Nepovedlo se inicializovat scénu");
        return;
    }
    initObjects();
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

    window = glfwCreateWindow(1000, 1000, "SOS0038", NULL, NULL);

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

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    float ratio = width / static_cast<float>(height);
    glViewport(0, 0, width, height);
    return true;
}

void Scene::run()
{
    GLfloat angle;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        drawObject(shaderProgram1, drawableObject1, model, angle, glm::vec3(0.6f, 0.0f, 0.0f));
        drawObject(shaderProgram2, drawableObject2, model2, angle, glm::vec3(-0.6f, 0.0f, 0.0f));

        angle += 0.5f;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
};

void Scene::initObjects()
{
    shaderProgram1.setId();
    shaderProgram2.setId();
    shaderProgram1.setShader(fragment_shader_src1, vertex_shader_src1);
    shaderProgram2.setShader(fragment_shader_src2, vertex_shader_src2);

    model = glm::mat4(1.0f);
    model2 = glm::mat4(1.0f);

    drawableObject1.initDrawableObject(shaderProgram1.getId(), model);
    drawableObject2.initDrawableObject(shaderProgram2.getId(), model2);
};

void Scene::initGeometry()
{
    GLfloat points[] = {
        -0.3f, -0.3f, -0.3f,
        0.3f, -0.3f, -0.3f,
        0.3f, 0.3f, -0.3f,
        -0.3f, 0.3f, -0.3f,
        -0.3f, -0.3f, 0.3f,
        0.3f, -0.3f, 0.3f,
        0.3f, 0.3f, 0.3f,
        -0.3f, 0.3f, 0.3f};

    GLuint indices[] = {
        0, 1, 2, 2, 3, 0, // Spodní stěna
        4, 5, 6, 6, 7, 4, // Horní stěna
        7, 3, 0, 0, 4, 7, // Zadní stěna
        6, 2, 1, 1, 5, 6, // Přední stěna
        7, 6, 5, 5, 4, 7, // Pravá stěna
        3, 2, 6, 6, 7, 3, // Levá stěna
    };

    GLfloat pyramidVertices[] = {
        -0.3f, -0.3f, -0.3f,
        0.3f, -0.3f, -0.3f,
        0.3f, -0.3f, 0.3f,
        -0.3f, -0.3f, 0.3f,
        0.0f, 0.3f, 0.0f,
        -0.3f, -0.3f, -0.3f,
        -0.3f, -0.3f, 0.3f,
        0.3f, -0.3f, 0.3f,
        0.3f, -0.3f, -0.3f};

    GLuint pyramidIndices[] = {
        // Spodní plocha
        0, 1, 2,
        2, 3, 0,

        // Stěny hranolu
        0, 4, 1,
        1, 4, 2,
        2, 4, 3,
        3, 4, 0,

        1, 5, 2,
        2, 5, 3};

    drawableObject1.initModel(points, indices, sizeof(points), sizeof(indices));
    drawableObject2.initModel(pyramidVertices, pyramidIndices, sizeof(pyramidVertices), sizeof(pyramidIndices));
}

void Scene::clean()
{
    glDeleteProgram(shaderProgram1.getId());
    glDeleteProgram(shaderProgram2.getId());
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Scene::drawObject(ShaderProgram shaderProgram, DrawableObject object, glm::mat4 model,
                       GLfloat angle, glm::vec3 translationVector)
{
    glUseProgram(shaderProgram.getId());
    object.transform(glm::translate(model, translationVector));
    object.transform(glm::rotate(object.getModel(), glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.5f)));
    object.render();
};