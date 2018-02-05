#pragma once
#include "IRenderLoop.hpp"
#include "Mesh.h"
class GSRender : public IRenderLoop
{
public:
	GSRender();
	~GSRender();
	void render();
	void addMesh(Mesh* mesh);
private:
	std::vector<SmartMesh> meshes;
};

