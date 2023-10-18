#include "../include/Scene.h"

const char *fragment_shader_src1 =
    "#version 330\n"
    "in vec3 fragColor;"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (fragColor, 1.0);"
    "}";

const char *vertex_shader_src1 =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "out vec3 fragColor;"
    "uniform mat4 model;"
    "void main () {"
    "     gl_Position = model * vec4(vp, 1.0);"
    "     fragColor = vp;"
    "}";

const char *fragment_shader_src2 =
    "#version 330\n"
    "out vec4 frag_colour;"
    "void main () {"
    "     frag_colour = vec4 (1.0, 1.0, 0.2, 1.0);"
    "}";

const char *vertex_shader_src2 =
    "#version 330\n"
    "layout(location=0) in vec3 vp;"
    "uniform mat4 model;"
    "void main () {"
    "     gl_Position = model * vec4(vp, 1.0);"
    "}";

Scene::Scene()
{
    if (!initWindow())
    {
        printf("Nepovedlo se inicializovat scénu");
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

    GLFWwindow *window = glfwCreateWindow(1000, 1000, "SOS0038", NULL, NULL);

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

    ShaderProgram shaderProgram1;
    shaderProgram1.setShader(fragment_shader_src1, vertex_shader_src1);
    ShaderProgram shaderProgram2;
    shaderProgram2.setShader(fragment_shader_src2, vertex_shader_src2);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 model2 = glm::mat4(1.0f);
    DrawableObject drawableObject1(shaderProgram1.getId(), model);
    DrawableObject drawableObject2(shaderProgram2.getId(), model2);

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
        // Spodní plocha
        -0.3f,
        -0.3f,
        -0.3f,
        0.3f,
        -0.3f,
        -0.3f,
        0.3f,
        -0.3f,
        0.3f,
        -0.3f,
        -0.3f,
        0.3f,
        0.0f,
        0.3f,
        0.0f,
        -0.3f,
        -0.3f,
        -0.3f,
        -0.3f,
        -0.3f,
        0.3f,
        0.3f,
        -0.3f,
        0.3f,
        0.3f,
        -0.3f,
        -0.3f,
    };

    GLuint pyramidIndices[] = {
        // Spodní plocha
        0,
        1,
        2,
        2,
        3,
        0,

        // Stěny hranolu
        0,
        4,
        1,
        1,
        4,
        2,
        2,
        4,
        3,
        3,
        4,
        0,

        1,
        5,
        2,
        2,
        5,
        3,
    };

    drawableObject1.initModel(points, indices, sizeof(points), sizeof(indices));
    drawableObject2.initModel(pyramidVertices, pyramidIndices, sizeof(pyramidVertices), sizeof(pyramidIndices));

    GLfloat angle;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram1.getId());
        drawableObject1.transform(glm::translate(model, glm::vec3(0.6f, 0.0f, 0.0f)));
        drawableObject1.transform(glm::rotate(drawableObject1.getModel(), glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.5f)));
        drawableObject1.render();

        glUseProgram(shaderProgram2.getId());
        drawableObject2.transform(glm::translate(model2, glm::vec3(-0.6f, 0.0f, 0.0f)));
        drawableObject2.transform(glm::rotate(drawableObject2.getModel(), glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.5f)));
        drawableObject2.render();

        angle += 0.5f;
        glfwSwapBuffers(window);
        // eventy jako resize okna atd.
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram1.getId());
    glfwDestroyWindow(window);
    glfwTerminate();
    return true;
};
