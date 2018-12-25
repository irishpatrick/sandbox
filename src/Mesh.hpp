#pragma once

#include "Geometry.hpp"
#include "Material.hpp"

class Mesh
{
public:
	Mesh();
	Mesh(Geometry&, Material&);
	~Mesh();

	void draw();

private:
	Geometry geometry;
	Material material;
};