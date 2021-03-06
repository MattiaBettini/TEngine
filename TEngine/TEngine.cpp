#include "stdafx.h"
#include "TEngine.h"
#include "Engine.h"

TEngine::IEngine* TEngine::TEngineFactory::m_pEngineInstance = nullptr;

void TEngine::TEngineFactory::CreateEngine(int iWidth, int iHeight, const string& wTitle, RenderSystem eRenderSubSystem)
{
	if (!m_pEngineInstance)
		m_pEngineInstance = new Engine(iWidth, iHeight, wTitle, eRenderSubSystem);
}


TEngine::IEngine* TEngine::TEngineFactory::GetEngine()
{
	if (m_pEngineInstance)
		return m_pEngineInstance;
	else
		throw exception("Engine not Initiazlized");	
}

void TEngine::TEngineFactory::ReleaseEngine()
{
	delete m_pEngineInstance;
	m_pEngineInstance = nullptr;
	//Rendere IEngine un oggetto non allocabile su stack
	//ed implementare la logica di distruzione qui dentro
	/*delete pEngine;*/
}
