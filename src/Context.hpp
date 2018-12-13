#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Context
{
public:
    Context();
    ~Context();

    void init();
    void clear();
    void flip();
    void destroy();
    GLFWwindow* getWindow();

private:
    GLFWwindow* window;
};