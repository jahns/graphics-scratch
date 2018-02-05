#pragma once
#include "stdafx.h"
#include "IRenderLoop.hpp"
class Window
{
public:
	Window(unsigned int width = 800, unsigned int height = 600);
	~Window();

	bool isWindowValid();
	void setLoopClass(std::shared_ptr<IRenderLoop> loop);
	void beginRender();

private:
	struct DeleteWindow {
		void operator()(GLFWwindow* ptr);
	};

	std::unique_ptr<GLFWwindow, DeleteWindow> m_Window;
	unsigned int m_Width, m_Height;
	bool m_IsValid;
	std::shared_ptr<IRenderLoop> m_loop;
};

