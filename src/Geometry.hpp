#pragma once

#include <GL/glew.h>
#include <cstdint>
#include <vector>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

class Geometry
{
public:
	Geometry();
	~Geometry();

private:
	std::vector<GLfloat> vertices;
};