#include "Geometry.hpp"
#include <iostream>

Geometry::Geometry()
{

}

Geometry::~Geometry()
{

}

void Geometry::init()
{

}

bool Geometry::genBuffers()
{
	if (vertices.size() == 0)
	{
		std::cout << "cannot init with 0 vertices" << std::endl;
		return false;
	}

	glGenBuffers(1, vbo);
	glGenVertexArrays(1, vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	uint32_t size = (vertices.size() * sizeof(GLfloat));
	glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], GL_STATIC_DRAW);

	glBindVertexArray(vao[0]);
	glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}

std::vector<GLfloat>& Geometry::getVertices() 
{
	return vertices;
}