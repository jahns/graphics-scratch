// graphicsscratch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Window.h"
#include "GSRender.h"
#include "Mesh.h"

int main()
{
	Window w(800, 600);
	std::shared_ptr<IRenderLoop> r(new GSRender());
	Mesh m;
	std::cout << w.isWindowValid() << std::endl;
	w.setLoopClass(r);
	w.beginRender();
    return 0;
}

