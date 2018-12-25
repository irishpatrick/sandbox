#include "CubeGeometry.hpp"
#include <algorithm>

static const GLfloat layout[24] =
{
	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, -1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, -1.0f
};

CubeGeometry::CubeGeometry()
{
	std::copy(layout, layout + 24, vertices.begin());
}

CubeGeometry::~CubeGeometry()
{

}

