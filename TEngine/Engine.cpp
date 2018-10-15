#include "stdafx.h"
#include "Engine.h"
#include "Scene2D.h"
#include "TEngine.h"
#include "MessageSetWindowSize.h"

Engine::Engine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eSystem)
{
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_sTitle = sTitle;

	m_pCurrentScene = dynamic_cast<Scene*>(CreateScene());
	m_pCurrentRenderMessages = &m_vQueue1;
	m_pCurrentUpdateMessages = &m_vQueue2;
}

Engine::~Engine()
{
	//delete m_pWindow;
}

void Engine::Run()
{
	thread t2(&Engine::RenderingInternalRoutine, this);
	m_vRendererThread.swap(t2);
	thread t3(&Engine::UpdateInternalRoutine, this);
	m_vUpdateThread.swap(t3);
	
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
	glfwSetWindowSizeCallback(m_pWindow, OnWindowResize);

	m_pCurrentScene->Init();

	while (!glfwWindowShouldClose(m_pWindow))
	{
		try// per ora usiamo un produttore-consumatore
		{
			//Log("--------Start New Frame--------");
			
			auto pTmp				 = m_pCurrentRenderMessages;
			m_pCurrentRenderMessages = m_pCurrentUpdateMessages;
			m_pCurrentUpdateMessages = pTmp;


			//signal to update thread to start
			m_vUpdateStart.Set();

			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			//glFlush();
			//Log("rendering");
			m_pCurrentScene->Render();
			

			glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
			glColor3f(1.0f, 0.0f, 0.0f); // Red
			glVertex2f(-0.5f, -0.5f);    // x, y
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, 0.5f);
			glEnd();

			/* Swap front and back buffers */
			glfwSwapBuffers(m_pWindow);

			//wait for update complete
			m_vUpdateComplete.WaitOne();

			/* Poll for and process events */
			glfwPollEvents();

			//UpdateDeltaTime();
		}
		catch (const std::exception& exc)
		{
			//TODO: do implementation
			fprintf(stderr, "Error: %s\n", exc.what());
		}
	}

	glfwTerminate(); //da chiamare alla chiusura della finestra
}

void Engine::UpdateInternalRoutine()
{
	
	//quando chiudiamo l' applicazione dobbiamo prima terminare il thread di rendering e poi quello di update
	while (m_pCurrentScene)
	{
		m_vUpdateStart.WaitOne();

		//cout << "updating" << endl;
		m_pCurrentScene->DeferredRemoveEntities();
		m_pCurrentScene->DeferredAddEntities();
		//Time::Update();
		m_pCurrentScene->PreUpdate();
		m_pCurrentScene->Update();
		m_pCurrentScene->PostUpdate();

		m_vUpdateComplete.Set();
	}
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
	return new Scene2D(this);
}

void Engine::Destroy(TEngine::IScene * pScene)
{
	delete pScene;
}

double Engine::GetDeltaTime()
{
	return m_dDeltaTime;
}

void Engine::UpdateDeltaTime()
{
	m_dCurrentFrame = glfwGetTime();
	m_dDeltaTime = m_dCurrentFrame - m_dLastFrame;
	m_dLastFrame = m_dCurrentFrame;
}

TEngine::IScene * Engine::GetCurrentScene()
{
	return m_pCurrentScene;
}

void Engine::GetWindowSize(int* pWidth, int* pHeight)
{
	glfwGetWindowSize(m_pWindow, pWidth, pHeight);
}

//Called by update thread
void Engine::RegisterRenderer(IMessage* pMessage)
{
	m_pCurrentUpdateMessages->push(pMessage);
}

void Engine::SetCurrentScene(TEngine::IScene* pScene)
{
	m_pCurrentScene = dynamic_cast<Scene* > (pScene);
	m_pCurrentScene->Init();
}

void Engine::OnWindowResize(GLFWwindow* pWindow, int iWidth, int iHeight)
{
	MessageSetWindowSize* x = MessageSetWindowSize::Get();
	
}