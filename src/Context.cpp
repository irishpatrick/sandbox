#include "Context.hpp"

Context::Context()
{

}

Context::~Context()
{

}

void Context::init()
{
    if (!glfwInit())
    {

    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
    if (!window)
    {
        
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        
    }

    glfwSwapInterval(1);
}

void Context::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::flip()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Context::destroy()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* Context::getWindow()
{
    return window;
}