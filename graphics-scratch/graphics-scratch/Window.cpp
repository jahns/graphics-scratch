#include "stdafx.h"
#include "Window.h"


Window::Window(unsigned int width, unsigned height): m_Width(width), m_Height(height)
{
	this->m_IsValid = true;
	if (!glfwInit()) {
		std::cerr << "GLFW failed to initialize" << std::endl;
		this->m_IsValid = false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
	this->m_Window.reset(glfwCreateWindow(this->m_Width, this->m_Height, "GScratch", NULL, NULL));
	if (this->m_Window.get() == NULL) {
		std::cerr << "Failed to create window" << std::endl;
		glfwTerminate();
		m_IsValid = false;
	}
	glfwMakeContextCurrent(this->m_Window.get()); // Initialize GLEW
	glewExperimental = true; // Needed in core profile

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize glew" << std::endl;
		this->m_IsValid = false;
	}
}


Window::~Window()
{
}


bool Window::isWindowValid() {
	return this->m_IsValid;
}


void Window::beginRender() {
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(this->m_Window.get(), GLFW_STICKY_KEYS, GL_TRUE);

	do {
		// Draw nothing, see you in tutorial 2 !
		this->m_loop->render();
		// Swap buffers
		glfwSwapBuffers(this->m_Window.get());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(this->m_Window.get(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		   glfwWindowShouldClose(this->m_Window.get()) == 0);
}

void Window::setLoopClass(std::shared_ptr<IRenderLoop> loop) {
	this->m_loop = loop;
}

void Window::DeleteWindow::operator()(GLFWwindow *ptr) {
	glfwDestroyWindow(ptr);
}