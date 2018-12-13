#include "Camera.hpp"

void Camera::setProjection(float fov, float aspect, float near, float far)
{
    projection = glm::perspective(
        glm::radians(fov),
        aspect,
        near,
        far
    );
}

void Camera::lookAt(float x, float y, float z)
{
    view = glm::lookAt(
        glm::vec3(x, y, z),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 1, 0)
    );
}

glm::mat4 Camera::getMatrix()
{
    return matrix;
}

glm::mat4 Camera::getProjection()
{
    return projection;
}

glm::mat4 Camera::getView()
{
    return view;
}

void Camera::update()
{
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
	matrix = translationMatrix;
}