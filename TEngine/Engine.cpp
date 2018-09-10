#include "stdafx.h"
#include "Engine.h"
#include "Scene.h"


Engine::Engine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eSystem)
{
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_sTitle = sTitle;
}

Engine::~Engine()
{
	//delete m_pWindow;
}

void Engine::Run()
{
	thread t2(&Engine::RenderingInternalRoutine, this);
	m_vRendererThread.swap(t2);
	
}

void Engine::RenderingInternalRoutine()
{
	if (!glfwInit())
		throw glfwInitException();

	m_pWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_sTitle.c_str(), NULL, NULL);
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

	glfwSetWindowCloseCallback(m_pWindow, OnWindowClosing);

	while (!glfwWindowShouldClose(m_pWindow))
	{
		try// per ora usiamo un produttore-consumatore
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(m_pWindow);

			/* Poll for and process events */
			glfwPollEvents();
		}
		catch (const std::exception& exc)
		{
			//TODO: do implementation
			fprintf(stderr, "Error: %s\n", exc.what());
		}
	}

	glfwTerminate(); //da chiamare alla chiusura della finestra
}

int Engine::GetWidth()
{
	return m_iWidth;
}

int Engine::GetHeight()
{
	return m_iHeight;
}

string Engine::GetTitle()
{
	return m_sTitle;
}

void Engine::Stop()
{
	m_vRendererThread.join();
}

void Engine::OnWindowClosing(GLFWwindow* pWindow)
{
	//TODO: Engine Closing 
	fprintf(stdout, "Window closed\n");
}

TEngine::IScene* Engine::CreateScene()
{
	return new Scene();
}

void Engine::Destroy(TEngine::IScene * pScene)
{
	delete pScene;
}
