#include <iostream>
#include <experimental/filesystem>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

#include "Context.hpp"
#include "Shader.hpp"
#include "TestTriangle.hpp"
#include "Camera.hpp"

namespace fs = std::experimental::filesystem;

Context ctx;
TestTriangle t;
Shader shader;
Camera camera;

void error_callback(int error, const char* desc)
{
    std::cerr << "error: " << desc << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void init()
{
    glfwSetErrorCallback(error_callback);
    ctx.init();
    glfwSetKeyCallback(ctx.getWindow(), key_callback);

    shader.loadShader(fs::path(fs::current_path() / "assets" / "vertex.glsl").generic_string(), GL_VERTEX_SHADER);
    shader.loadShader(fs::path(fs::current_path() / "assets" / "fragment.glsl"), GL_FRAGMENT_SHADER);
    shader.linkProgram();

    t.init();

    camera.setProjection(70.0f, 640.0f/480.0f, 0.1f, 100.0f);
    //camera.lookAt(4.0f, 3.0f, 4.0f);
    camera.position.z = -2.0f;
}

void update()
{
    t.rotation.y += 0.5f;
    camera.update();
    t.update();
}

void draw()
{
    ctx.clear();

    shader.use();
    glm::mat4 mvp = camera.getProjection() * camera.getMatrix() * t.getMatrix();
    shader.setMatrix4("mvp", mvp);
    t.draw();

    ctx.flip();
}

void loop()
{
    while (!glfwWindowShouldClose(ctx.getWindow()))
    {
        update();
        draw();
    }
}

void destroy()
{
    ctx.destroy();
}

int main(int argc, char* argv[])
{
    std::cout << "hello world" << std::endl;
    
    init();
    loop();
    destroy();

    return 0;
}