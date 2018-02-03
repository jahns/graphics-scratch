// graphicsscratch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Window.h"

int main()
{
	Window w(800, 600);
	std::cout << w.isWindowValid() << std::endl;
	w.beginRender();
    return 0;
}

