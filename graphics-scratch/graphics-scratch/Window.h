#pragma once
#include "IRenderLoop.h"
class Window
{
public:
	Window(unsigned int width = 800, unsigned int height = 600);
	~Window();

	bool isWindowValid();
	void setLoopMethod(IRenderLoop* loop);
	void beginRender();

private:
	std::shared_ptr<GLFWwindow> m_Window;
	unsigned int m_Width, m_Height;
	bool m_IsValid;
	std::unique_ptr<IRenderLoop> m_loop;
};

