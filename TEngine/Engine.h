#define GLEW_STATIC
#pragma once

#include "TEngineLib.h"
#include "EngineException.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <GL/GL.h>

//#pragma comment(lib, "opengl32.lib")

class Engine : public TEngine::IEngine
{
public:
	Engine(int iWidth, int iHeight, const string& wTitle, TEngine::RenderSystem eSystem);
	virtual ~Engine();

	virtual void Run() override;

private:

	//function<void(GLFWwindow*)> GLFWindowDeleter = [](GLFWwindow* ptr) { glfwDestroyWindow(ptr); };

	//unique_ptr<GLFWwindow, decltype(GLFWindowDeleter)> m_pWindow;

	GLFWwindow* m_pWindow;
};


