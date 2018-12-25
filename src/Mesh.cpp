#include "Mesh.hpp"

Mesh::Mesh()
{
	
}

Mesh::Mesh(Geometry& g, Material& m)
{
	geometry = g;
	material = m;
}

Mesh::~Mesh()
{

}

void Mesh::draw()
{

}