#pragma once
#include "stdafx.h"
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include "Vertex.h"
#include "Texture.h"
#include "Shader.h"


class Mesh{
public:
	std::vector<Vertex> m_verts;
	std::vector<unsigned int> m_indices;
	std::vector<Texture> m_textures;

	Mesh();
	Mesh(std::vector<Vertex> verts, std::vector<unsigned int> indices, std::vector<Texture> textures);
	~Mesh();
	void drawMesh(Shader shader);
private:
	void initializeMesh();
	unsigned int m_VAO, m_VBO, m_EBO;
};

typedef std::shared_ptr<Mesh> SmartMesh;