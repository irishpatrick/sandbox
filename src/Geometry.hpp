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

	void init();
	bool genBuffers();

	std::vector<GLfloat>& getVertices();

protected:
	GLuint vbo[1];
	GLuint vao[1];
	GLuint positionAttributeIndex = 0;
	std::vector<GLfloat> vertices;

};