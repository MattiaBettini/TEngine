#pragma once
#include "stdafx.h"
#include "TEngine.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <GL/GL.h>
#include "EngineException.h"
#include "AutoResetEvent.h"

//using namespace TEngine;

class Scene;
class IScene;
class Logger;
class IMessage;

class Engine final : public TEngine::IEngine
{
public:
	Engine(int iWidth, int iHeight, const string& sTitle, TEngine::RenderSystem eSystem);

	virtual void Run() override;
	virtual void Stop() override;
	virtual int GetWidth() override;
	virtual int GetHeight() override;

	virtual string GetTitle() override;
	virtual void SetCurrentScene(TEngine::IScene* pScene);	
	virtual TEngine::IScene* GetCurrentScene() override;
	virtual void GetWindowSize(int * pWidth, int * pHeight) override;

	void RegisterRenderer(IMessage* pMessage);

private:
	virtual ~Engine();
	void RenderingInternalRoutine();
	void UpdateInternalRoutine();
	void UpdateDeltaTime();

	thread m_vRendererThread;
	thread m_vUpdateThread;
	GLFWwindow* m_pWindow;
	static void OnWindowClosing(GLFWwindow* pWindow);
	static void OnWindowResize(GLFWwindow* pWindow, int iWidth, int iHeight);
	int m_iWidth;
	int m_iHeight;
	string m_sTitle;
	Scene* m_pCurrentScene;

	double m_dCurrentFrame;
	double m_dDeltaTime;
	double m_dLastFrame;

	AutoResetEvent m_vUpdateStart;
	AutoResetEvent m_vUpdateComplete;

	// Inherited via IEngine
	virtual TEngine::IScene * CreateScene() override;
	virtual void Destroy(TEngine::IScene * pScene) override;

	virtual double GetDeltaTime() override;

	queue<IMessage*> m_vQueue1;
	queue<IMessage*> m_vQueue2;
	queue<IMessage*>* m_pCurrentRenderMessages;
	queue<IMessage*>* m_pCurrentUpdateMessages;


};