#pragma once
#include "stdafx.h"
#include "TEngine.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <GL/GL.h>
#include "EngineException.h"

class Engine final : public TEngine::IEngine
{
public:
	Engine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eSystem);

	virtual void Run() override;
	virtual void Stop() override;
	virtual int GetWidth() override;
	virtual int GetHeight() override;
	virtual string GetTitle() override;

private:
	virtual ~Engine();
	void RenderingInternalRoutine();

	thread m_vRendererThread;
	GLFWwindow* m_pWindow;
	static void OnWindowClosing(GLFWwindow* pWindow);
	int m_iWidth;
	int m_iHeight;
	string m_sTitle;

	// Inherited via IEngine
	virtual TEngine::IScene * CreateScene() override;
	virtual void Destroy(TEngine::IScene * pScene) override;
};