#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh() {

}

Mesh::Mesh(std::vector<Vertex> verts, std::vector<unsigned int> indices, std::vector<Texture> textures) : m_verts(verts), m_indices(indices), m_textures(textures) {

}

Mesh::~Mesh() {

}

void Mesh::drawMesh(Shader shader) {

}

void Mesh::initializeMesh() {
	glGenVertexArrays(1, &this->m_VAO);
	glGenBuffers(1, &this->m_VBO);
	glGenBuffers(1, &this->m_EBO);

	glBindVertexArray(this->m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);

	glBufferData(GL_ARRAY_BUFFER, this->m_verts.size() * sizeof(Vertex), &this->m_verts[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(unsigned int), &this->m_indices[0], GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_normal));
	// vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_uv));

	glBindVertexArray(0);
}