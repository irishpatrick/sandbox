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

	bool init();

protected:
	GLuint vbo[1];
	GLuint vao[1];
	const GLuint positionAttributeIndex = 0;
	std::vector<GLfloat> vertices;

};