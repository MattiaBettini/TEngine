#include "stdafx.h"
#include "Engine.h"


TEngine::Engine::Engine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eSystem)
{
	if (!glfwInit())
		throw glfwInitException();

	m_pWindow = glfwCreateWindow(iWidth, iHeight, sTitle.c_str(), NULL, NULL);
	if (!m_pWindow)
	{
		glfwTerminate();
		throw glfwCreateWindowException();
	}

	glfwMakeContextCurrent(m_pWindow);

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}

TEngine::Engine::~Engine()
{
	delete m_pWindow;
}

void TEngine::Engine::Run()
{
	while (!glfwWindowShouldClose(m_pWindow))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(m_pWindow);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate(); //da chiamare alla chiusura della finestra
}
