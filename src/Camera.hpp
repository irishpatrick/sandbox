#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

class Camera
{
public:
    Camera()
    {
        matrix = glm::mat4(1.0f);
        position = glm::vec3(0.0f);
    }

    ~Camera()
    {

    }

    void setProjection(float, float, float, float);
    void lookAt(float, float, float);

    glm::mat4 getProjection();
    glm::mat4 getView();
    glm::mat4 getMatrix();

    void update();

    glm::vec3 position;
    glm::vec3 rotation;

private:
    glm::mat4 matrix;
    glm::mat4 projection;
    glm::mat4 view;
};