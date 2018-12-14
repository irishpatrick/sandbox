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

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_SAMPLES, 4);
    window = glfwCreateWindow(
		mode->width, mode->height, 
		"Title", 
		glfwGetPrimaryMonitor(), NULL
	);
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