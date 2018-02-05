#include "stdafx.h"
#include "GSRender.h"


GSRender::GSRender()
{
}


GSRender::~GSRender()
{
}


void GSRender::render() {
	glClearColor(.5f, .5f, .5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GSRender::addMesh(Mesh* mesh) {
	this->meshes.push_back(SmartMesh(mesh));
}